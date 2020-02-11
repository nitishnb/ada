/* given a sorted array with repeated integers u need to find first, last occurance and count of the key in the array and your algorithm should run in log n time, if element is not found print -1
use only binary search */


#include<iostream>
using namespace std;

int main()
{
	int n,a[100],ele,high,low=0,mid,flag=0,temp,count=0,first,last;
	cout << "Enter the size : \n";
	cin >> n;
	high=n-1;
	cout << "Enter" <<n<<" elements : ";
	for(int i;i<n;i++)
	{	
		cin >> a[i];
	}	
	cout << "Enter element to be search :";
	cin >> ele;
	while(high>=low)
	{
		mid=(high+low)/2;
		if(a[mid]==ele){
			flag=1;
			temp = mid;
			while(mid>=0 && a[mid]==ele){
				first=mid+1;
				count++;
				mid--;
			}
		        last=mid = temp+1;
			while(mid<n && a[mid]==ele){
				last=mid+1;
				count++;
				mid++;
			}
			cout <<ele<<" is first occured at "<<first<<" and last occured at "<<last<<"\n";
			cout <<ele<<" is appeared "<<count<<" times"<<"\n";
			break;
		}
		else if(a[mid]<ele)
			low=mid+1;
		else
			high=mid-1;
	}
	if(flag==0)
	    cout << "-1"; 
	cout << "\nEnd of Binary search\n";
	return 0;
}

