/* Given an integer N which is a multiple of 4, the task is to find an N x N grid for which the bitwise xor of every row and column is same*/

#include <bits/stdc++.h> 
using namespace std; 

void findGrid(int n) 
{ 
	int arr[n][n]; 
	int x = 0; 
	for (int i = 0; i < n / 4; i++)
		for (int j = 0; j < n / 4; j++)  
			for (int k = 0; k < 4; k++) 
				for (int l = 0; l < 4; l++) 
				{
					arr[i * 4 + k][j * 4 + l] = x; 
					x++; 
				}
	for (int i = 0; i < n; i++)  
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " "; 
		cout << "\n"; 
} 


int main() 
{ 
	int n;
	cout<<"N(multiple of 4)=";
	cin>>n;
    
	findGrid(n); 

	return 0; 
} 
