/* Following two programs to be executed in the next week.
‌
a) Sort a given set of N integer elements using Insertion Sort technique and compute its time taken. 
‌
b) There is one meeting room in a firm. There are N meetings in the form of (Si, Fi) where Si is the start time of meeting i and Fi is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers */



#include <stdlib.h>
#include <iostream>

using namespace std;


void insertionSort(int a[], int length) 
{
    int i, j, key;
    for (i = 1; i < length; i++) 
    {
        key = a[i];
        j = i-1;
        
        while (j >= 0 && a[j] >key) 
        {
            a[j+1] = a[j];
            j--;
        }
        a[j +1] = key;
        
    }
    cout << "Sorted Array: ";
    for (int j = 0; j < length; j++)
    {
        cout <<" "<< a[j];  
    }
}


int main() 
{
    int a[100],n;
    clock_t time;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++)
	cin>>a[i];
    time = clock();
    insertionSort(a, n);
    time=clock()-time;
    cout << "Processor time taken in pow function: "<< (float)time/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}



