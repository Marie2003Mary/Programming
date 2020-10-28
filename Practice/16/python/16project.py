i = 1
f=0
step=0
c = 'Ответ:'
print("Введите количество билетов")
k=int(input())
print("Введите номера билетов")
for i in range (k):
    q=str(input())
    if q[0] == 'a' and q[4] == '5' and q[5] == '5' and q[6] == '6' and q[7] == '6' and q[8] == '1':
        c = c + ' ' + q
    else:
        f = f + 1
    step = step + 1
if f == k:
    print("-1")
else:
    print(c)

