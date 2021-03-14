#include <iostream>

using namespace std;

int* create(int d, int p = 0, int step = 0)
{
    int *array = new int[d];
    array[0]= p;
    for (int i = 1; i< d; i++ )
    {
        array[i] = array[i-1] + step;
    }
    return array;
}
int* Sort(int* array,int n){
    for(int i=1;i<n;i++){
        for(int j=i; j>0 && array[j-1]>array[j];j--){
            int tmp=array[j-1];
           array[j-1]=array[j];
            array[j]=tmp;
        }
    }
    return array;
}
int* print(int *array , int d)
{   std::cout << "[";
    int i=0;
    while(1){
        cout << array[i] ;
        i++;
        if(i<d-1)  cout << ", ";
        else
        {
            std::cout << "]";
        return array;
           }
  }
}
int main()
{ int l, p_e, st;
    cout << "Input l ,p_e, st"<<endl;
    cin >> l >>p_e>> st;
    int* a = create( l, p_e,st );
    print(Sort(a,l), l);
    delete [] a;
}
