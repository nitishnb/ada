/*b) Write a program for the following: Given an array arr[] of size N. The task is to find the sum of the digits of all array elements which contains even number of 1’s in it’s their binary representation*/

#include<iostream>

using namespace std;

bool even(int n)
{
	int i;
	for(i=0; n>0; i++)
	n = n & (n-1);
	if(i%2==0)
	return true;
	return false;
}

int sum(int n)
{
	int sum = 0;
	while(n>0)
	{
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}


int main()
{
	cout<<"Enter the size of array: ";
	int n, i;
	cin>>n;
	cout<<"Enter the array: ";
	int arr[n];
	for(i=0; i<n; i++)
	cin>>arr[i];
	int S = 0;
	for(i=0; i<n; i++)
	{
		if(even(arr[i]))
		S += sum(arr[i]);
	}
	cout<<"Sum is: "<<S;
	return 0;
}
