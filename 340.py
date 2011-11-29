results = {}

a = 21**7
b = 7**21
c = 12**7
#a = 50
#b = 2000
#c = 40

def f(n):
    global a,b,c,modulo,results
    if results.has_key(n):
        return results[n]
    else:
        if n > b:
            results[n] = n - c
            return results[n]
        else:
            c1 = f(a+n)
            c2 = f(a+c1)              
            c3 = f(a+c2)
            comp = f(a+c3)
            results[n] = comp
            return comp



def s():
    global b
    sum = 0
    for i in xrange(b, -1, -1):
        sum += f(i) % 10**9
        print i,b
        
    return sum

print s()
