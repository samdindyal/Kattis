#!/usr/bin/ruby

line_count = STDIN.gets.chomp.to_i

$keys = STDIN.gets.chomp.split(" ").sort
$graph = Hash.new

line_count.times do
	input = STDIN.gets.chomp.split(" ")
	$graph[input[0]] = input[2, line_count+2].sort
end


def dfs(node, stack, result)
	if stack.empty? && $keys.empty?
		result << node
		return result
	elsif ($graph[node] & $keys) && !(($graph[node] & $keys).empty?)
		stack.unshift (node)
		result << node
		$keys.delete node
		dfs(($graph[node] & $keys).shift, stack, result)
	elsif !stack.empty?
		result << node
		$keys.delete node
		dfs(stack.shift, stack, result)
	elsif !$keys.empty?
		result << node
		node = $keys.shift
		dfs(node, stack, result)
	end
end

res = dfs($keys.shift, [], []).uniq
res.delete nil
puts res