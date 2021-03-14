import builtins
def create(d,p,st):
    ar = [p]
    a = p
    for i in range(d):
        a = a+st
        ar.append(a)
    return ar


def sort(ar,d):
    for i in range(1, len(ar)):
        tmp = ar[i]
        j = i - 1
        while (j >= 0 and tmp < ar[j]):
            ar[j + 1] = ar[j]
            j = j - 1
        ar[j + 1] = tmp
    return ar



def print(ar,d):
    builtins.print("[",end = "")
    for i in range(d):
        if(i+1 == d):
            builtins.print(ar[i], end = "")
        else:
            builtins.print(ar[i], end = ",")
    builtins.print("]")
    ar.clear()


d = int(input("Введите размер массива "))
p = int(input("Введите начало массива "))
st = int(input("Введите шаг арифметической прогрессии "))
print(sort(create(d,p,st),d),d)
