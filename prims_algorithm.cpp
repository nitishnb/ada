/*Find Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm.*/

#include <bits/stdc++.h> 
using namespace std; 

int n;
int graph[20][20];


int minKey(int k[], bool m[]) 
{ 
	int min = INT_MAX, min_index; 
    for (int v = 0; v < n; v++) 
		if (m[v] == false && k[v] < min) 
			min = k[v], min_index = v; 
    return min_index; 
} 


 
void primMST() 
{ 
	int p[n]; 
	int k[n]; 
	bool m[n]; 
	for (int i = 0; i < n; i++) 
		k[i] = INT_MAX, m[i] = false;  
	k[0] = 0; 
	p[0] = -1; 
	for (int count = 0; count < n - 1; count++) 
	{ 
		int u = minKey(k, m); 
		m[u] = true; 
		for (int v = 0; v < n; v++) 
			if (graph[u][v] && m[v] == false && graph[u][v] < k[v]) 
				p[v] = u, k[v] = graph[u][v]; 
	} 
	cout<<"Edge \tWeight\n"; 
	for (int i = 1; i < n; i++) 
	    cout<<p[i]<<" - "<<i<<" \t"<<graph[i][p[i]]<<" \n"; 
} 


int main() 
{ 
    cout<<"Enter the no. of vertices:  ";
    cin>>n;
    cout<<"Enter the adjacency matrix:  "<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
	primMST(); 

	return 0; 
} 
