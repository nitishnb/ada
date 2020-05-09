/*Write a program for the following: The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.*/

#include<iostream>  
using namespace std; 
    
    
int l( int a[], int n )  
{  
    int l[n]; 
    l[0] = 1;    
    for (int i = 1; i < n; i++)  
    { 
        l[i] = 1; 
        for (int j = 0; j < i; j++)   
            if (a[i]>a[j] && l[i]<l[j]+1)  
                l[i] = l[j] + 1;  
    } 
    return *max_element(l, l+n); //returns maximum value in l[n]
}  
    
    
int main()  
{  
    int n;
    cin>>n;
    int a[n];  
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Length of list is "<<l(a,n)<<endl;  
    return 0;  
}
