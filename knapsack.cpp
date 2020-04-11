/*Implement 0/1 Knapsack problem using dynamic programming*/

#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the no. of objects:"<<endl;
    cin>>n;
    cout<<"Enter the maximum capacity of bag: "<<endl;
    cin>>m;
    int p[n+1],wt[n+1];
    cout<<"Enter the array of profits:"<<endl;
    p[0]=0;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    cout<<"Enter the array of weights:"<<endl;
    wt[0]=0;
    for(int i=1;i<=n;i++)
        cin>>wt[i];
    int k[n+1][m+1];
    for(int i=0;i<=n;i++)
        for(int w=0;w<=m;w++)
        {
            if(i==0 || w==0)
                k[i][w]=0;
            else if(wt[i]<=w)
                k[i][w]=max(p[i]+k[i-1][w-wt[i]],k[i-1][w]);
            else
                k[i][w]=k[i-1][w];
        }
    cout<<"Maximum profit = "<<k[n][m]<<endl;
    int i=n, j=m;
    cout<<"Objects selected(0=not selected, 1=selected)"<<endl;
    while(i>0 && j>=0){
        if(k[i][j]==k[i-1][j]){
            cout<<i<<"=0"<<endl;
            i--;
        }
        else{
            cout<<i<<"=1"<<endl;
            j=j-wt[i];
            i--;
        }
    }
    return 0;
}
