/*Implement Johnson Trotter algorithm to generate permutations.*/

#include <iostream>

using namespace std;

bool rightToLeft = false;
bool leftToRight = true;

int searchArray(int arr[], int n, int mobile)
{
    for(int i = 0; i < n; i++)
    {
        if (arr[i] == mobile)
            return i+1;
    }
}

int findMobile(int a[], int n, bool dir[])
{
    int mobile = 0, mobilePrev = 0;
    for(int i = 0; i < n; i++)
    {
        if ((dir[a[i]-1] == rightToLeft) && i != 0)
        {
            if ((a[i] > a[i-1]) && a[i] > mobilePrev)
            {
                mobile = a[i];
                mobilePrev = mobile;
            }
        }
        if ((dir[a[i]-1] == leftToRight) && i != n-1)
        {
            if ((a[i] > a[i+1]) && a[i] > mobilePrev)
            {
                mobile = a[i];
                mobilePrev = mobile;
            }
        }
    }
    if (mobile == 0 && mobilePrev == 0)
        return 0;
    else
        return mobile;
}

int displayOnePermutation(int a[], int n, bool dir[])
{
    int mob = findMobile(a, n, dir);
    int pos = searchArray(a, n, mob);
    if (dir[a[pos-1]-1] == rightToLeft)
        swap(a[pos-1], a[pos-2]);
    else if (dir[a[pos-1]-1] == leftToRight)
        swap(a[pos], a[pos-1]);
    for(int i = 0; i < n; i++)
    {
        if (a[i] > mob)
        {
            if (dir[a[i]-1] == leftToRight)
                dir[a[i]-1] = rightToLeft;
            else if (dir[a[i]-1] == rightToLeft)
                dir[a[i]-1] = leftToRight;
        }
    }
    for(int i = 0; i < n; i++)
        cout << a[i];
    cout << " ";
}

int factorial(int n)
{
    int result = 1;
    for(int i = 1; i <= n; i++)
        result = result * i;
    return result;
}

void displayAllPermutations(int n)
{
    int a[n];
    bool dir[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        cout << a[i];
    }
    cout << " ";
    int fact = factorial(n);
    for(int i = 0; i < n; i++)
        dir[i] = rightToLeft;
    for(int k = 1; k < fact; k++)
        displayOnePermutation(a, n, dir);

}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The possible permutations are: " << endl;
    displayAllPermutations(n);
    return 0;
}
