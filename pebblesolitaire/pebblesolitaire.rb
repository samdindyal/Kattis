#!/usr/bin/ruby

def solve line
    if @map[line] || (@min = [@min, line.count('o')].min) <= 1
        return @map[line]
    end
    
    if line.include?('oo-') || line.include?('-oo')
	    (line.size-2).times do |x|
	    		substring = line[x...(x+3)]
	    		if  substring == "oo-"
		            i = (line[x..(line.size)].index 'oo-') + x
		            str = line[0, i] + '--o' + line[(i+3), (line.size)]
		            @map[line] = solve str
	        	end

	    		if substring == "-oo"
		            i = (line[x..(line.size)].index '-oo') + x
		            str = line[0, i] + 'o--' + line[(i+3), (line.size)]
					@map[line] = solve str
	        	end
	    end
	end
end

n = gets.chomp.to_i

n.times do
	@map = {}

	line = gets.chomp
	@min = line.size

	solve line
	puts @min
end
