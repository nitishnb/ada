/*Given a directed graph with N vertices and M edges that may contain cycles, the task is to find the lexicographically smallest topological ordering of the graph if it exists otherwise print -1 (if the graph has cycles). Lexigraphically smallest topological ordering means that if two vertices in a graph do not have any incoming edge then the vertex with the smaller number should appear first in the ordering.*/

#include <iostream>

using namespace std;

int a[10][10], k, indegree[10], temp[10];

void topo(int v)
{
    k = 0;
    for(int i = 1; i <= v; i++)
    {
        if(indegree[i] == 0)
        {
            indegree[i] = 1;
            temp[++k] = i;
            for(int j = 1; j <= v; j++)
            {
                if((a[i][j] == 1) && (indegree[j] != -1))
                {
                    indegree[j]--;

                }
            }
            i=0;
        }
    }
}

int main()
{
    int v;
    cout << "Enter the number of vertices : ";
    cin >> v;
    cout << "Enter the adjacency matrix : " << endl;
    for(int i = 0; i <= v; i++)
    {
        indegree[i] = 0;
    }
    for(int i = 1; i <= v; i++)
        for(int j = 1; j <= v; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1)
                indegree[j]++;
        }
    topo(v);
    if(k != v)
        cout << "There is no topological ordering";
    else
    {
        for (int i = 1; i <= v;i++)
            cout << temp[i] << " ";
    }
    return 0;
}
