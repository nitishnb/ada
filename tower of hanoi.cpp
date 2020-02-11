#include<iostream>
using namespace std;
int count=0;
int hanoi(int, char, char,char);

int main()
{
  int n;
  cout << "Enter no. of discs: ";
  cin >> n;
  hanoi(n,'A','C','B');
  cout << "count : "<< count<<endl;
}

int hanoi(int n, char x, char y,char z)
{
	if(n>0) 
	{
      		hanoi(n-1,x,z,y);
      		printf("%c to %c\n",x,y);
      		hanoi(n-1,z,y,x);
		count++;
   	}
}
