require "PP"
guesses = 0
matches = 0 
k = 20000
n = 1000000

while true
    array = [0]*n
    k.times do
        index = rand(n)
        array[index] = array[index] + 1
    end
    
    sum = 0
    array.each do |i|
        if i >= 3
            sum += 1
        end
    end
    
    if sum >= 1
        matches += 1
    end
    
    guesses += 1.0
    if matches & (8-1) == 0 
        puts (matches/guesses)
    end
end
