print("Введите сумму,затем начальное и конечное значения диапазонов")
s, l1, r1,  l2, r2 = input().split(' ')
step = 0
s = int (s)
l1 = int (l1)
r1 = int (r1)   
r2 = int (r2)   
l2 = int (l2) 
if ((s > (r1 + r2)) or (s < (l1 + l2))):
    print("-1")
else:
    if ((s - l1) >= l2):
        if (s <= (l1 + r2)):
            print(l1," ",s - l1)
        else:
            step = abs(s - (l1 + r2))
            if ((l1 + step) < r1 and (r2 - step) > l2):
                print(l1 + step," ",s - (l1 + step))
            else:
                print("-1")
    else:
        print("-1")
