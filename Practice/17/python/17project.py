p = 37
n = 0
b = 0
k = 0
i = 0
q=0
black =[ 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35]
a = [0] * p
for i in range (37):
    a[i] = 0
while (True):
    u=0
    o=0
    p=0 
    y = int(input())
    if y < 0:
        break
    else:
        a[y] = a[y] + 1
        for q in range (18):
            if y == black[q]:
                b=b+1
                break
            elif q == 17:
                k=k+1
                break
        for u in range (37):
            if a[u] > n:
                n = a[u]
        for o in range (37):
            if a[o] == n:
                print(o,end = '\n')
        for p in range (37):
            if a[p] == 0:
                print(p,end = ' ')
        print("\n","Красные: ",k, " Черные: " ,b, "\n")
