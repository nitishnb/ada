/*b) Given an array of 0s and 1s, If any particular index i has value 1 then it is a safe index and if the value is 0 then it is an unsafe index. A man is standing at index -1(source) can only land on a safe index and he has to reach the Nth index (last position). At each jump, the man can only travel a distance equal to any Fibonacci Number. You have to minimize the number of steps, provided man can jump only in forward direction.*/

#include<bits/stdc++.h> 

using namespace std;

void fib(int arr[], int  n)
{
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i<n; i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}
}

int jump (bool arr[], int n, int fib[])
{
	int temp[n+2];
	temp[0] = 0;
	int test;
	for(int i=1; i<n+2; i++)
		temp[i] = (INT_MAX-1);
	
	for(int i=1; i<=n+1; i++)
	{
		for(int j=1; j<n; j++)
		{
			if((arr[i-1]==1 || i == n+1)&&i-fib[j]>=0)
			{
				test = 1 + temp[i-fib[j]];
				if(test<temp[i]) 
				temp[i] = test;
			}
		}
	}
	if (temp[n+1] == INT_MAX-1)
	return -1;
	return temp[n+1];
}


int main()
{
	cout<<"Enter the size of the array: ";
	cout<<INT_MAX;
	int size;
	cin>>size;
	bool arr[size];
	cout<<"Enter the values: ";
	for(int i=0; i<size; i++)
	{
		cout<<i<<": ";
		cin>>arr[i];
	}
	int Fibbonachi[size];
	
	fib(Fibbonachi,size);
	for(int i=0; i<size; i++)
	{
		cout<<Fibbonachi[i]<<"\t";
		
	}
	cout<<"Answer: "<<jump(arr,size,Fibbonachi);
}
