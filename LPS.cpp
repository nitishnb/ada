/* Given a sequence, find the length of the longest palindromic subsequence in it. */

#include<iostream>
#include<string.h>
using namespace std; 
  
int l(char *s, int i, int j) 
{ 
    if (i == j) 
        return 1; 
    if (s[i] == s[j] && i + 1 == j) 
        return 2; 
    if (s[i] == s[j]) 
        return l (s, i+1, j-1) + 2; 
    return max( l(s, i, j-1), l(s, i+1, j) ); 
} 
  
  
int main() 
{ 
    char s[30];
    cout<<"Enter the string : ";
    cin>>s;
    int n = strlen(s); 
    cout << "The length of the Longest Palindromic Subsequence(LPS) is " 
         << l(s, 0, n-1); 
    return 0; 
} 
