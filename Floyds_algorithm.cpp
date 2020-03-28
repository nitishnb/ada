/*13. a)Implement All Pair Shortest paths problem using Floyd’s algorithm.*/

#include<bits/stdc++.h> 

using namespace std;

void input(int matrix[][10], int n)
{
	for(int i=0; i<n; i++)
	{
		char out = 65+i;
		cout<<"Is "<<out<<" Connected with : \n";
		for(int j=0; j<n; j++)
		{
			if(j==i)
			{
				matrix[i][j] = 0;
				continue;
			}
			char in = 65 +j;
			cout<<in<<": ";
			int a;
			cin>>a;
			if(a<1)
			a = (INT_MAX/3) -1;
			matrix[i][j] = a;
		}
	}
}

void display(int matrix[][10], int n)
{
	system("cls");
	char out;
	for(int j=0; j<n; j++)
	{
			out = 65+j;
			cout<<"    "<<out<<"    ";
	}
	cout<<endl<<"\t ";
	for(int j=0; j<n; j++)
	{
		cout<<"---------";
	}
	cout<<endl;
	for(int i =0; i<n; i++)
	{
		out = 65+i;
		cout<<"    "<<out<<"    ";
		for(int j=0; j<n; j++)
		{
			cout<<"|  ";
			if(matrix[i][j]>9)
				cout<<matrix[i][j]<<" ";
			else
				cout<<" "<<matrix[i][j]<<" ";
			cout<<"  |";
		}
		cout<<endl<<"\t ";
		for(int j=0; j<n;j++)
		{
			cout<<"---------";
		}
		cout<<endl;
	}
}

void Floyds(int matrix[][10], int n)
{
	int test;
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				test = matrix[i][k] + matrix[k][j];
				if(test<matrix[i][j])
				matrix[i][j] = test;
			}
		}
	}
}


int main()
{
	cout<<"Enter the size: ";
	int n;
	cin>>n;
	cout<<"Enter the directed graph: ";
	int matrix[n][10];
	input(matrix,n);
	Floyds(matrix,n);
	display(matrix,n);
	return 0;
}
