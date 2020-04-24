/* Write a program for minimum coin changing problem using Greedy technique.*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void calculate(int n){
    int count=0;
    int deno[]={1 , 2, 5, 10, 20, 50, 100, 500, 2000};
    vector<int> res;
    for(int i=8; i>=0; i--)
        while(n>=deno[i]){
            n-=deno[i];
            res.push_back(deno[i]);
            count++;
        }
    cout<<"No. of coins or notes required are :  "<<count<<endl;
    cout<<"Denominations required are :  ";
    for(int j=0;j<res.size();j++)
        cout<<res[j]<<" ";
}

int main(){
    int n;
    cin>>n;
    calculate(n);
}
