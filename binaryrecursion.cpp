#include<iostream>
#include<bits/stdc++.h> 
using namespace std;


int binary(int a[], int low, int high, int x) 
{ 
   if (high >= low) 
   { 
        int mid =(low+high)/2; 
        if (a[mid] == x)  
		return mid; 
        if (a[mid] > x)
		return binary(a, low, mid-1, x); 
        return binary(a, mid+1, high, x); 
   } 
   return -1; 
}


int main()
{
	int a[100],n, high, low, ele, pos; 
    	clock_t time; 
	cout << "Enter the size of elements: ";
	cin >> n;
	cout << "Enter the elements:";
	for(int i=0;i<n;i++)
		cin >> a[i];
	high = n-1;
	low = 0;
	cout << "Enter the element to be searched :"<<endl;
	cin >> ele;
	time = clock();
	pos = binary(a, low, high ,ele);
	if(pos==-1)
		cout <<ele<<" is found not found"<<endl;
	else
		cout <<ele<<" is found at "<<pos+1<<" position."<<endl;
	time = clock() - time;
	cout << "Processor time taken in pow function: "<< (double)time/CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}
