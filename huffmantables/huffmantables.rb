#!/usr/bin/ruby

class HuffmanNode
  attr_reader   :value
  attr_reader   :frequency
  attr_reader   :children
  attr_reader   :leaf_nodes_list
  attr_accessor :huffman_string

  def initialize(value = '', frequency = 0)
    @value      = value
    @frequency  = frequency
    @children   = []
  end

  def to_s
    "#{@frequency}#{@value}#{children[0]}#{children[1]}"
  end
end

class HuffmanTree
  attr_reader  :leaf_nodes
  attr_reader  :root_node
  attr_reader  :non_leaf_nodes

  def initialize(string = '')

    @non_leaf_nodes = []

    @leaf_nodes = string.upcase.split('').uniq.sort.inject({}) do
        |h, k|
        h[k] = HuffmanNode.new(k, string.count(k))
        h
     end

     @root_node = build_huffman_tree leaf_nodes.values
     accumulate_huffman_strings @root_node
  end

  def build_huffman_tree node_array
    if node_array.count <= 1
      return node_array[0]
    end

    node_array.sort_by! { |n| [n.frequency, n.value, n.to_s] }

    first_smallest = node_array.delete_at(0)
    second_smallest = node_array.delete_at(0)

    new_node = HuffmanNode.new('', first_smallest.frequency + second_smallest.frequency)
    node_array << new_node
    @non_leaf_nodes << new_node

    node_array[-1].children << first_smallest
    node_array[-1].children << second_smallest

    build_huffman_tree node_array
  end

  def accumulate_huffman_strings starting_node
    if starting_node.children.empty?
      return
    end

    # Preprend huffman string with appropriate digit
    starting_node.children[0].huffman_string = "#{starting_node.huffman_string}0"
    starting_node.children[1].huffman_string = "#{starting_node.huffman_string}1"

    # Recurse
    accumulate_huffman_strings starting_node.children[0]
    accumulate_huffman_strings starting_node.children[1]
  end
end

# Get the input and turn it into tree
input = gets.chomp

tree = HuffmanTree.new(input)

nodes = tree.leaf_nodes.values.sort_by { |n| [n.frequency, n.value] }

nodes.each_with_index do |x, i|
  puts "L#{i} #{x.value} #{x.frequency} #{x.huffman_string}"
end

puts

node_collection = {}

leaf_counter = 0
node_counter = 0

tree.non_leaf_nodes.each do |node|
  if !node_collection[node.children[0]]
    node_collection[node.children[0]] = "L#{leaf_counter}"
    leaf_counter += 1
  end

  if !node_collection[node.children[1]]
    node_collection[node.children[1]] = "L#{leaf_counter}"
    leaf_counter += 1
  end

  if !node_collection[node]
    node_collection[node] = "N#{node_counter}"
    node_counter += 1
  end
  puts "#{node_collection[node]} #{node.frequency} #{node_collection[node.children[0]]} #{node_collection[node.children[1]]}"
end
