/*Sort a given set of N integer elements using Quick Sort technique and compute its time taken*/

#include<iostream>
#include<ctime>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
            if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quicksort(int a[], int l, int h){
    if(l<h){
        int j=partition(a, l, h);
        quicksort(a, l, j-1);
        quicksort(a, j+1, h);
    }
}



int main(){
    int n;
    clock_t time;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    time = clock();
    quicksort(a, 0, n-1);
    time=clock()-time;
    cout<<endl<<"The sorted elements after quicksort process are: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout <<endl<< "Processor time taken in pow function: "<< (float)time/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}

