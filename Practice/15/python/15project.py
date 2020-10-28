import random
while(1):
    i=1
    r=random.randint(1,100)
    x=int(input("Доброго времени суток игрок!У вас есть 5 попыток угадать число, вперёд"))
    for i in range (4):
        if (x < a):
            print("Значение больше введённого")
        elif (x > a):
            print("Значение меньше введённого")
        else:
            print("Поздравляю!Вы угадали\n")
            break
        x = int(input())
    if (x != a):
        print("Вы проиграли, загаданное число - ", a, "\n")
    print ("ЧТобы начать новую игру  - введите 1")
    k = int(input())
    if (k != 1):
        break

        
        
