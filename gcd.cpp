#include <iostream>

using namespace std;

int gcdeuc(int, int);
int gcdrep(int, int);
int gcdcon(int, int, int);
int gcdmid(int, int);

int main()
{
	int m,n;
	cout << "Enter the numbers:" << endl;
	cin >> m >> n;
	cout << "The GCD using euclid's method is = " << gcdeuc(m, n)<<endl;
	cout << "The GCD using repiitive subtraction is = " << gcdrep(m,n)<<endl;
	int small = min(m,n);
	cout << "The GCD using consecutive integer checking is = " << gcdcon(m,n,small)<<endl;
	cout << "The GCD using middle school method is = " << gcdmid(m,n)<<endl;
	return 0;
}

int gcdeuc(int a, int b)
{
	if(b==0)
		return a;
	else		
		return gcdeuc(b, a%b);
}

int gcdrep(int m,int n)
{
    if(m>n)
        gcdrep(m-n,n);
    else if(m<n)
        gcdrep(m,n-m);
    else if(m==n)
        return m;
}

int gcdcon(int a, int b, int small)
{
	if(a%small==0 && b%small==0)
		return small;
	else 
		return gcdcon(a,b,small-1);
}

int gcdmid(int a, int b)
{
	int c, ans=1;
	c=min(a,b);
	for(int i=2;i<=c;i++)
	{
		int n=0,m=0;
		if(a%i==0)
		{
			a=a/i;
			n=1;
		}
		if(b%i==0)
		{
			b=b/i;
			m=1;
		}
		if(n==1 && m==1)
			ans =ans*i;
		if(n==1 || m==1)
			i=i-1;
		
	}
	return ans;
}
