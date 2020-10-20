r=1

z=int(input("¬ведение число,а затем степень "))

s=int(input())

if (s >= 0):

    while (s != 0):
        
        r = r * z
        
        s = s - 1
    
    print(r)
 

else:
    
    while (s != 0):
        
        r = r * z
        
        s = s + 1
    
        print(1 / r)