#include<iostream>
using namespace std;

void swap(int *a,int *b);

int main()
{
	int a,b;
	a=5;b=10;
	cout<<"Before Swiping "<<"a = "<<a<<" and b= "<<b;
	
	swap(&a,&b);
	cout<<"after swiping "<<"a = "<<a<<" and b= "<<b;
}
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
	cout<<"\n\n inside function";
	cout <<"after swaping "<<"a = "<<*a<<" and b = "<<*b;
}


