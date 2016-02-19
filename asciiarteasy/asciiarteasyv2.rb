#!/usr/bin/env ruby

def sol
	# input = [ws, hs, wt, ht]
	input = gets.split(' ').map(&:to_i)

	s = Array.new
	(1..(input[1])).each do ||
		s << gets.chomp
	end

	t = Array.new

	(1..(input[3])).each do ||
		t << gets.chomp
	end	

	counter = 0

	s.each_with_index do |line, y|
		if !(index = line.index t[counter])
			counter = 0
		elsif counter < input[3] - 1
			counter += 1
		else
			return "#{index} #{y-counter}"
		end
	end

	return "no match"
end

puts sol