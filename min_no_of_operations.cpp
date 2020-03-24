/*Given two text strings A of length n and B of length m, to transform A into B using a minimum number of operations of the following types: delete a character from A, insert a character into A, or change some character in A into a new character. The minimal number of such operations required to transform A into B is called the edit distance between A and B. For example, the edit distance(abbc, xbbacd) = 3 (change a to x; insert a after bb; insert d after c) Find a recurrence relation that is useful to find the edit distance of two strings A and B. Take an example of two strings of which one is your own name, and using this relation, fill the table for the minimum number of operations.*/

#include <iostream>
#include <cstring>

using namespace std;

int minimum(int x, int y, int z)
{
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    else
        return z;
}

int minOperations(char a[], char b[], int k, int l)
{
    if (k == 0)
        return l;
    if (l == 0)
        return k;
    if (a[k-1] == b[l-1])
        return minOperations(a, b, k-1, l-1);
    else
        return 1 + minimum(minOperations(a, b, k-1, l), minOperations(a, b, k, l-1), minOperations(a, b, k-1, l-1));
}

int main()
{
    char str1[20], str2[20];
    int len1, len2;
    cout << "Enter first string: ";
    cin >> str1;
    len1 = strlen(str1);
    cout << "Enter second string: ";
    cin >> str2;
    len2 = strlen(str2);
    int result = minOperations(str1, str2, len1, len2);
    cout << "The minimum operations possible is " << result;
    return 0;
}
