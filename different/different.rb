#!/usr/bin/env ruby

STDIN.each_line do |line|
	input = line.split(' ').map(&:to_i)
	puts (input[0] - input[1]).abs
end