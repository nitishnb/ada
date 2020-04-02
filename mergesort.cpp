/*a) Sort a given set of N integer elements using Merge Sort technique and compute its time taken. Run the program for different values of N and record the time taken to sort.*/

#include<iostream>
#include<ctime>
using namespace std;

void mergearray(int a[], int l, int mid, int h)
{
    int n = mid-l+1 , m= h-mid;
    int L[n], R[m];
    for (int i = 0; i < n; i++)
        L[i] = a[l + i];
    for (int j = 0; j < m; j++)
        R[j] = a[mid + 1+ j];
    int i=0,j=0,k=l;
    while(i<n && j<m)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while(i<n)
        a[k++] = L[i++];
    while(j<m)
        a[k++] = R[j++];
}

void mergesort(int a[], int l, int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a, l, mid);
        mergesort(a, mid+1, h);
        mergearray(a, l , mid, h);
    }
}

int main(){
    int n,a[100];
    clock_t time;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    cout<<"Enter the array elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    time = clock();
    mergesort(a, 0, n-1);
    time=clock()-time;
    cout<<"The array after merge-sort is: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"   ";
    cout << "Processor time taken in pow function: "<< (float)time/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
