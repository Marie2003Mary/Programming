#include <iostream>
#include <string>
#include <cmath>
#include <locale>

using namespace std;

void create(int **v, const int d, const int p ,  const int step)
{
    int *array = new int[d];
    *array= p;
    for (int i = 1; i< d; i++ )
    {
        *(array + i) = *(array + i -1) + step;
    }
    *v = array;
}
void Sort(int* v, const int d){
    for(int i=1;i<d;i++){
        for(int j=i; j>0 && v[j-1]>v[j];j--){
            int tmp=*(v+j-1);
           *(v+j-1)=*(v+j);
            *(v+j)=tmp;
        }
    }
}
void print(int *v , const int d)
{   std::cout << "[";
    int i=0;
    for (int i = 0; i < d; i++)
    {
        if (i < d - 1)
        {
            std::cout << *(v + i) << ",";
        }
        else
        {
            std::cout << *(v + i);
        }
     }
     std::cout << "]";
}
void destroy (int**v)
{
    delete[]*v;
    *v = nullptr;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int l, p_e = 0, st = 0;
    cout << "Input  l, p_e, st"<<endl;
    cin >> l >>p_e>> st;
    int *v;
    create(&v ,l ,p_e,st);
    Sort(v,l);
    print(v,l);
    destroy(&v);
}
