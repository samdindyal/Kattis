var line;

while (line = readline()) {
    var nums = line.split(' ');
    print(Math.abs(parseInt(nums[0]) - parseInt(nums[1])));
}