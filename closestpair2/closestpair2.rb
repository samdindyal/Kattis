#!/usr/bin/ruby

def calculate_distance(p1, p2)
    Math.sqrt(((p1[0] - p2[0])**2) + ((p1[1] - p2[1]))**2)
end

def find_closest_pair_brute_force points
    closest_points = Array.new
    closest_points[2] = Float::INFINITY

    points[0, points.count - 1].each_with_index do |p1, i|
        points[i+1, points.count].each do |p2|
            if (current_distance = calculate_distance(p1, p2)) < closest_points[2]
                closest_points[0] = p1
                closest_points[1] = p2
                closest_points[2] = current_distance

            end
        end
    end
    return closest_points
end

def find_closest_pair_recursive points
    if points.count <= 3
        return find_closest_pair_brute_force points
    end

    n = points.count
    mid = n/2

    left = right = nil

    left = find_closest_pair_recursive(points[0, mid]) 
    right = find_closest_pair_recursive(points[mid, n], ) 
    median = points[mid]
    closer_points = Array.new

    min = left[2] < right[2] ? left : right


    points.each do |point|
        if (point[0] - median[0]).abs < min[2]
            closer_points << point
        end
    end

    points.sort_by! { |p| [p[1], p[0]] }

    closer_points[0, closer_points.count - 1].each_with_index do |p1, i|
        closer_points[i+1, closer_points.count].each do |p2|
            if (p1[1] - p2[1]).abs < min[2]
                min[0] = p2
                min[1] = p1
                min[2] = calculate_distance(p1, p2)
            end
        end
    end
    return min
end

def run points
    output = ""
    points.sort_by! { |p| [p[0], p[1]] }
    if points.count <= 3
        solution = find_closest_pair_brute_force points 
    else
        solution = find_closest_pair_recursive(points)
    end
    
    solution[0, solution.count-1].each do |x|
        output += "#{x[0]} #{x[1]} "
    end
    return output
end

counter = 0
solutions = Array.new
threads = Array.new
points = Array.new


until (point_count = gets.to_i) == 0  do
    points[counter] = Array.new

    point_count.times do 
        point_in = gets.split(' ').map(&:to_f)
        points[counter].push point_in
    end

    solutions[counter] = (run points[counter])
    counter += 1
end

counter.times do |i|
    puts solutions[i]
end
