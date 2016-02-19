#!/usr/bin/env ruby

def sol
	input = Array.new

	# input[0] = [ws, hs, wt, ht]
	input[0] = gets.split(' ').map(&:to_i)

	if input[0].size !=  4 || input[0][0] <= 0 || input[0][1] > 1000 || input[0][2] <= 0 || input[0][2] > input[0][0] || input[0][3] <= 0 || input[0][3] > input[0][1]
		exit
	end

	(1..(input[0][1] + input[0][3])).each do |i|
		input[i] = gets.chomp
	end

	input[1, input[0][1] - (input[0][3] - 1)].each_with_index do |value, i|
		input[1 + input[0][1], input[0][3]].each_with_index do |key, j|
			next if !(index = input[1+i+j].index key)
			if j+1 == input[0][3]
				return "#{index} #{i}"
			end
		end
	end
	return "no match"
end

puts sol