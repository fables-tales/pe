$results = {}

$a = 50
$b = 2000
$c = 40
$modulo = 10**9

def f(n)
    if $results.has_key?(n)
        return results[n]
    else
        if n > $b
            $results[n] = n-$c
            return results[n]
        else
            comp = f($a+f($a+f($a+f($a+n))))
            $results[n] = comp
            return comp
        end
    end
end


f(0)
