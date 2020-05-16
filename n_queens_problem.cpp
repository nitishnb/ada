/*Implement “N-Queens Problem” using Backtracking*/

#include <iostream> 
#define N 4 
using namespace std;

void print(int b[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            cout<<b[i][j]; 
        cout<<"\n"; 
    } 
} 

bool isSafe(int b[N][N], int r, int c) 
{ 
    int i, j; 
    for (i = 0; i < c; i++) 
        if (b[r][i]) 
            return false; 
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--) 
        if (b[i][j]) 
            return false;
    for (i = r, j = c; j >= 0 && i < N; i++, j--) 
        if (b[i][j]) 
            return false; 
  
    return true; 
} 

bool solve(int b[N][N], int c) 
{ 
    if (c >= N) 
        return true;
    for (int i = 0; i < N; i++) 
    { 
        if (isSafe(b, i, c)) 
        { 
            b[i][c] = 1; 
            if (solve(b, c + 1)) 
                return true; 
            b[i][c] = 0; 
        } 
    } 
    return false; 
} 

bool solveNQ() 
{ 
    int b[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
  
    if (solve(b, 0) == false) { 
        cout<<"Solution does not exist"; 
        return false; 
    } 
  
    print(b); 
    return true; 
} 

int main() 
{ 
    solveNQ(); 
    return 0; 
} 
