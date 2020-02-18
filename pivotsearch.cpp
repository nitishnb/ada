#include <iostream>


int Pivot (int[], int, int);

int binarySearch (int[], int, int, int);

int pivotedsearch (int arr[], int n, int key)

{

  int pivot = Pivot (arr, 0, n - 1);
 
 if (pivot == -1)
    
return binarySearch (arr, 0, n - 1, key);
 
 if (arr[pivot] == key)
   
 return pivot;
 
 if (arr[0] <= key)
   
 return binarySearch (arr, 0, pivot - 1, key);
 
 else
   
 return binarySearch (arr, pivot + 1, n - 1, key);
}



int Pivot (int arr[], int low, int high)

{

  if (high < low)
   
 return -1;
 
 if (high == low)
  
  return low;
  
int mid = (low + high) / 2;
 
 if (mid < high && arr[mid] > arr[mid + 1])
  
  return mid;
 
 if (mid > low && arr[mid] < arr[mid - 1])
  
  return (mid - 1);
 
 if (arr[low] >= arr[mid])
   
 return Pivot (arr, low, mid - 1);
  
else
    return Pivot (arr, mid + 1, high);

}



int binarySearch (int arr[], int low, int high, int key)

{

  if (high < low)
   
 return -1;
  
int mid = (low + high) / 2;
 
 if (key == arr[mid])
    
return mid;
  
if (key > arr[mid])
   
 return binarySearch (arr, (mid + 1), high, key);
 
 else
   
 return binarySearch (arr, low, (mid - 1), key);

}



int main ()

{
  
int arr1[50], key, n;
 
 printf ("\nEnter size");
 
 scanf ("%d", &n);
  
printf ("\nEnter ele in array");
  
for (int i = 0; i < n; i++)
   
 {

      scanf ("%d", &arr1[i]);

    }
 
 printf ("\nEnter ele to be searched");
 
 scanf ("%d", &key);
 
 printf ("\nIndex of the element is : %d", pivotedsearch (arr1, n, key));
 
 return 0;

}
