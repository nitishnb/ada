/*17.a)Implement “Sum of Subsets” using Backtracking. “Sum of Subsets” problem: Find a subset of a given set S = {s1,s2,……,sn} of n positive integers whose sum is equal to a given positive integer d. For example, if S = {1,2,5,6,8} and d = 9 there are two solutions {1,2,6} and {1,8}. A suitable message is to be displayed if the given problem instance doesn’t have a solution.*/

#include <bits/stdc++.h> 
using namespace std; 
  

void subsetsum(vector<int>& a, vector<vector<int> >& r, vector<int>& subset, int pos, int d) 
{ 
    int sum=accumulate(subset.begin(), subset.end(), 0);
    int rem_sum=0;
    if(d == sum)
        r.push_back(subset);
    for (int i = pos; i < a.size(); i++)
        rem_sum+=a[i];
    if((sum+a[pos])<=d)
        if(sum+rem_sum>=d)
            for (int i = pos; i < a.size(); i++) { 
                subset.push_back(a[i]); 
                subsetsum(a, r, subset, i + 1, d);
                subset.pop_back(); 
            } 
    return; 
} 
  
   
vector<vector<int>> subsets(vector<int>& a, int d) 
{ 
    vector<int> subset; 
    vector<vector<int> > r; 
    int pos = 0; 
    subsetsum(a, r, subset, pos, d);
    return r; 
} 
  
  
int main() 
{ 
    vector<int> a ={1,2,5,6,8};
    int d=9;
    vector<vector<int> > r = subsets(a,d);
    for (int i = 0; i < r.size(); i++) { 
        cout<<"{ ";
        for (int j = 0; j < r[i].size(); j++) 
            cout << r[i][j] << " "; 
        cout<<"}"<< endl; 
    } 
    return 0; 
}
