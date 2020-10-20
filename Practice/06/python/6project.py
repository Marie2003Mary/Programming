import math

a=float(input(u' '"Введите значение перменной a = "));
b=float(input(u' '"Введите значение перменной b = "));
c=float(input(u' '"Введите значение переменной c = "));

d=(b*b)-(4*a*c);

if ((d >= 0)&(((a!=0)&(b!=0))|((a!=0)&(c!=0))|((b!=0)&(c!=0)))):
    
    if (a != 0):
        
        x1 = (-b - (math.sqrt(d))) / (2 * a)
        
        x2 = (-b + (math.sqrt(d))) / (2 * a)
        
        if (x1==x2):
                
            print("x=",x1)
        
        else:
                
            print("x1 = ",x1)
                
            print("x2 = ",x2)
    
    else:
        
        x = (-c / b)
        
        print("x = ",x)

if ((d < 0)|((a==0)&(b==0)&(c!=0))):
    
    print("Нет решения")

if (((b == 0) & (c == 0)&(a!=0)) | ((a == 0) & (c == 0)&(b!=0))):
   
    if (a!=0):
        
        print("x = ",0/a)
    
    if (b!=0):
        
        print("x = ",0/b)

if ((a == 0) & (b == 0) & (c == 0)):
    
    print("Все корни верны")
