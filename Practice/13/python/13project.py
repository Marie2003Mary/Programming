import math
n=2
i=int(input("Введите значение "))
while n<=math.sqrt(i):
    if i % n == 0: 
        print("Число ",i ," составное")
        break;
    else:
        print("Число", i, " простое")
        break;
  
