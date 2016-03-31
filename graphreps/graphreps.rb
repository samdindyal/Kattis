#!/usr/bin/ruby

args = gets.chomp.split(" ")

if args.count != 2 || args[0] != "Graph"
	exit
end

i = args[1].to_i

graphs = 
[
	"a" => "0 0 1 1 0 0",
	"b" => "0 0 1 0 0 1",
	"c" => "1 1 0 0 1 0",
	"d" => "1 0 0 0 1 0",
	"e" => "0 0 1 1 0 1",
	"f" => "0 1 0 0 1 0"
],

[
	"a" => "0 0 1 0 0",
	"b" => "0 0 1 0 0",
	"c" => "1 1 0 1 1",
	"d" => "0 0 1 0 0",
	"e" => "0 0 1 0 0"
],
[
	"a" => "0 1 1 1 1 0 0",
	"b" => "1 0 0 1 0 1 0",
	"c" => "1 0 0 0 0 0 1",
	"d" => "1 1 0 0 0 1 0",
	"e" => "1 0 0 0 0 0 1",
	"f" => "0 1 0 1 0 0 0",
	"g" => "0 0 1 0 1 0 0"
]


print "* "

graphs[i-1][0].keys.each_with_index do |x, index|
	print "#{x}"
	if index < graphs[i-1][0].size - 1
		print " "
	end
end

puts


graphs[i-1].each do |x|
	x.each do |key, row|
		puts "#{key} #{row}"
	end
end

puts

output = [
	"a" => "c d",
	"b" => "c f",
	"c" => "a b e",
	"d" => "a e",
	"e" => "c d f",
	"f" => "b e"
],

[
	"a" => "c",
	"b" => "c",
	"c" => "a b d e",
	"d" => "c",
	"e" => "c"
],
[
	"a" => "b c d e",
	"b" => "a d f",
	"c" => "a g",
	"d" => "a b f",
	"e" => "a g",
	"f" => "b d",
	"g" => "c e"
]

output[i-1].each do |map|
	map.each do |key, value|
		puts "#{key} | #{value}"
	end
end
