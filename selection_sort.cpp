#include<iostream>
#include<ctime>
using namespace std;

void swap(int* p,int* q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

void selectionsort(int a[], int n)
{
    for(int j=0; j<n-1; j++)
        for(int i=j+1; i<n; i++)
            if(a[i]<a[j])
                swap(&a[i],&a[j]);
    for(int i=0; i<n; i++)
        cout<<a[i]<<"\t";
}

int main()
{
    int n;
    clock_t time;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    time = clock();
    selectionsort(a,n);
    time=clock()-time;
    cout <<endl<< "Processor time taken in pow function: "<< (float)time/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
