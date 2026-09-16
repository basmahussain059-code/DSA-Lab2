#include<iostream>
using namespace std;
int *swap(int **a,int **b)
{
    int temp;
    temp=**a;
    **a=**b;
    **b=temp;
    return *a,*b;
}
int main()
{
    int a=5, b=10; 
	int *pa=&a; 
	int *pb=&b;
    int **ppa=&pa;
	int **ppb=&pb;
    cout<<"Before swapping: a = "<<a<<", b = "<<b<<endl;
    swap(ppa,ppb);
    cout<<"After swapping : a = "<<a<<" b = "<<b<<endl;
}