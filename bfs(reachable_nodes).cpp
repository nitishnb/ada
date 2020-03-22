/*
i) Print all the nodes reachable from a given starting node in a digraph using BFS method.
*/

#include<iostream>
using namespace std;

int a[20][20],q[20],visited[20],r=-1,f=0,i,j,n;

void bfs(int v){
        for(i=1;i<=n;i++)
                if(a[v][i] && !visited[i])
                    q[++r]=i;
        if(f<=r){
            visited[q[f]]=1;
            bfs(q[f++]);
        }
}

int main(){
    int v;
       cout<<"Enter no. of vertices"<<endl;
       cin>>n;
       for(i=1;i<=n;i++)
        {
         q[i]=0;
         visited[i]=0;
        }
       cout<<"Enter Adjacency Matrix of the graph:"<<endl;
         for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
              cin>>a[i][j];
              }
            }
         cout<<"Enter the node of ur Choice:"<<endl;
         cin>>v;
         bfs(v);
         cout<<"All the nodes reachable from node->"<<v<<" is/are : "<<endl;
         for(i=1;i<=n;i++){
             if(visited[i])
                cout<<i<<"\t";
                }
         return(0);
}



