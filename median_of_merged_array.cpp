/* There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n))*/

#include<iostream>
#include<ctime>
using namespace std;


int median(int a[], int n){
    return (n%2)?((a[n-1]+a[n])/2):a[n/2];
}

int getmedian(int L[], int R[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return (L[0] + R[0]) / 2;
    if (n == 2)
        return (max(L[0], R[0]) + min(L[1], R[1])) / 2;
    int m1=median(L, n);
    int m2=median(R, n);
    if (m1==m2)
        return m2;
    if (m1 < m2){
        if(n%2==0)
            return getmedian(L+n/2-1, R, n-n/2+1);
        return getmedian(L+n/2, R, n-n/2);
    }
    if(n%2==0)
        return getmedian(R+n/2-1, L, n-n/2+1);
    return getmedian(R+n/2, L, n-n/2);
}

int main(){
    int n,a[100], b[100];
    clock_t time;
    cout<<"Enter the size of the arrays:"<<endl;
    cin>>n;
    cout<<"Enter the array 1 elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the array 2 elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>b[i];
    time = clock();
    cout<<getmedian(a, b, n)<<" is the median of the merged array"<<endl;
    time=clock()-time;
    cout << "Processor time taken in pow function: "<< (float)time/CLOCKS_PER_SEC << " seconds" << endl;
    cout<<"Time Complexity : O(logn)"<<endl;
    return 0;
}
