def innersum
    steps = 0
    x = 0
    while x != (2**32) - 1
        x = x | rand(2**32)
        steps += 1 
    end
    
    return steps
end

attempts = 0.0
steps = 0

while true
    steps += innersum
    attempts += 1

    if (steps & (4096-1) == 0)
        puts steps/attempts
    end
end
