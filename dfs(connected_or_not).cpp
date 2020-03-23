#include<iostream>
using namespace std;

void dfs(int n,int adj[10][10],int u,int s[])
{
    int v;
    s[u]=1;
    for(v=0;v<n;v++)
    {
        if(adj[u][v]==1 && s[v]==0)
            dfs(n,adj,v,s);
    }
}


int main()
{
    int n,i,j,adj[10][10],s[10],connected,flag;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"Enter the adjacency matrix"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    connected=0;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
            s[i]=0;
        dfs(n,adj,j,s);
        flag=0;
        for(i=0;i<n;i++)
        {
            if(s[i]==0)
            flag=1;
        }
        if(flag==0)
            connected=1;
    }
    if(connected==1)
        cout<<"graph is connected"<<endl;
    else
        cout<<"graph is not connected"<<endl;
    return 0;
}
