#include<iostream>
using namespace std;

int recSearch(int arr[], int l, int r, int x) 
{ 
    if (r < l) 
        return -1; 
    if (arr[l] == x) 
        return l; 
    if (arr[r] == x) 
        return r; 
    return recSearch(arr, l + 1, r - 1, x); 
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
	cout << "Enter the element to be searched :"<<endl;
	cin >> ele; 
	time = clock();
	pos = recSearch(a, 0, n - 1, ele);
	if(pos==-1)
		cout <<ele<<" is found not found"<<endl;
	else
		cout <<ele<<" is found at "<<pos+1<<" position."<<endl;
	time = clock() - time;
	cout << "Processor time taken in pow function: "<< (double)time/CLOCKS_PER_SEC << " seconds" << endl;
}
