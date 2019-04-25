#include <iostream>
  
using namespace std; 
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n, int b) 
{ 
    int i, j, min_idx; 
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        // SOLUTION HERE n = b
        if(arr[i] > arr[i+1]){
            // n=b
            for (j = i+1; j < b; j++) 
            if (arr[j] < arr[min_idx]) 
              min_idx = j; 
    
          // Swap the found minimum element with the first element 
          swap(&arr[min_idx], &arr[i]); 
        }
    } 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {64, 25, 12, 22, 11}; 
    // B is given by the question;
    int b; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionSort(arr, n, b); 
    cout << "Sorted array: " << endl; 
    printArray(arr, n); 
    return 0; 
} 