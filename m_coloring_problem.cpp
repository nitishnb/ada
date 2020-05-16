/* Write a program for the following: Given an undirected graph and a number m, determine if the graph
can be colored with at most m colors such that no two adjacent vertices of the graph are colored with 
the same color. Here coloring of a graph means the assignment of colors to all vertices.*/

#include<iostream> 
#define V 5 
using namespace std;

void printSolution(int color[]); 



bool isSafe (int v, bool g[][V], int color[], int c) 
{ 
	for (int i = 0; i < V; i++) 
		if (g[v][i] && c == color[i]) 
			return false; 
	return true; 
} 


bool coloring(bool g[][V], int d, int color[], int v) 
{ 
	if (v == V) 
		return true; 
	for (int c = 1; c <= d; c++) 
	{ 
		if (isSafe(v, g, color, c)) 
		{ 
		color[v] = c; 
		if (coloring (g, d, color, v+1) == true) 
			return true; 
		color[v] = 0; 
		} 
	} 
	return false; 
} 


void gColoring(bool g[][V], int d) 
{ 
	int color[V]; 
	for (int i = 0; i < V; i++) 
	color[i] = 0; 
	if (coloring(g, d, color, 0) == false) 
	{ 
	cout<<"Solution does not exist"; 
	return ; 
	} 
    cout<<"The graph can be colored with at most "<<d<<" color";
	return ; 
} 


int main() 
{ 
	bool g[V][V] = {{0, 1, 1, 1, 1}, 
		{1, 0, 1, 0, 0}, 
		{1, 1, 0, 0, 1}, 
		{1, 0, 0, 0, 0},
		{1, 0, 1, 0, 0}
	}; 
	int d = 3; 
	gColoring(g, d); 
	return 0; 
} 
