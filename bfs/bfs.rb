#!/usr/bin/ruby

line_count = STDIN.gets.chomp.to_i

$keys = STDIN.gets.chomp.split(" ").sort
$graph = Hash.new

line_count.times do
	input = STDIN.gets.split(" ")
	$graph[input[0]] = input[2, line_count+2].sort
end

def sol queue
	if $keys.empty? && queue.empty?
		return
	end
	node = queue.shift
	if node
		puts node
	end
	if !$graph[node]
		queue << $keys.shift
		sol queue
	else
		queue = (queue + ($graph[node] & $keys))
		$keys = $keys - $graph[node]
		sol queue
	end
end

queue = [$keys.shift]
sol queue