#include<iostream>
using namespace std;


int a[100],b[100],n;

void insert()
{
    int i, j, key,temp;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        temp= b[i];
        j = i-1;
       
        while (j >= 0 && a[j] >key)
        {
            a[j+1] = a[j];
            b[j+1] = b[j];
            j--;
        }
        a[j +1] = key;
    b[j +1] = temp;
    }
}

void count(){
int i,c=1;
cout<<"["<<a[0]<<","<<b[0]<<"]"<<endl;
for(i=1;i<n;i++)
{
if(a[i]>=b[i-1])
{
cout<<"["<<a[i]<<","<<b[i]<<"]"<<endl;
c++;
}
}
cout<<"Total no. of meetings ="<<c<<endl;
}

int main()
{
cout<<"Enter the total no. of meetings ";
cin>>n;
cout<<"Enter the array of starting times: ";
for(int i=0;i<n;i++)
cin>>a[i];
cout<<"Enter the array of finishing times: ";
for(int i=0;i<n;i++)
cin>>b[i];
insert();
count();
return 0;
}
