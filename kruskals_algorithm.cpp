/*Find Minimum Cost Spanning Tree of a given undirected graph using Kruskals algorithm*/

#include<bits/stdc++.h>
using namespace std; 
int parent[30]; 

int find(int i) 
{ 
	while (parent[i]!=i) 
	        i = parent[i]; 
	return i; 
} 


void unionv(int i, int j) 
{ 
	int a = find(i); 
	int b = find(j); 
   	parent[a] = b; 
} 


void kruskals(int a[][30], int n) 
{ 
	int mincost = 0,c = 0,i,j; 
	for(i=0;i<n;i++) 
        	parent[i] = i; 
	cout<<"\nThe Minimum Spanning Tree is :\n";
	cout<<"Edges\tWeight\n";
	while(c<n-1) 
	{ 
	   int min = 10000,it = -1,jt = -1; 
	   for(i=0;i<n;i++) 
	        for(j=0;j<n;j++) 
		        if(find(i)!=find(j) && a[i][j]<min)
				{ 
                    	min = a[i][j]; 
                        it = i; 
                    	jt = j; 
                } 
  		unionv(it,jt);
		c++; 
        cout<<"("<<it+1<<","<<jt+1<<")\t"<<min<<"\n";  
        mincost += min; 
    } 
    cout<<"\nMinimum cost = "<<mincost<<"\n"; 
}


int main() 
{
	int a[30][30],n,i,j;
	cout<<"Enter the number of vertices";
	cin>>n;
	cout<<"Enter the weight matrix of the graph (Enter 9999 for infinity)"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	kruskals(a,n);
	return 0; 
} 
