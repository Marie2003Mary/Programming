c1, o, c2= input('������� ���������: ').split()
c1, c2 = map(float, [c1, c2])
if (o=='+'):
    print("��������� ���������:",c1+c2)
if (o=='-'):
    print("��������� ���������:",c1-c2)
if (o=='*'):
    print("��������� ���������:",c1*c2)
if (o=='/'):
    if (c2 == 0):
        print("��� ������� ������ ��������� �� 0 ���������� �������������� ���������")
    else:
        print("��������� ���������:",c1/c2)
if((o !='+')&(o != '-')&(o != '*')&(o != '/')):
    print("����� ������������ ������ ��� ����")