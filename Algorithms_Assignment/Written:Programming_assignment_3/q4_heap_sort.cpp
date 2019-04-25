#include <iostream> 
#include <algorithm>
using namespace std; 
void printArray(int arr[], int n);
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1  GET LEFT
    int r = 2*i + 2; // right = 2*i + 2  GET RIGHT
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n, int b) 
{ 
    // Build heap (rearrange array) 
    // BUILD MAX-HEAP
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    printArray(arr, n);
    cout << "testing\n";
    // One by one extract an element from heap
    int temp_for_b = b;
    for (int i=n-1, cnt = b; i>=0; i--, cnt--)
    {
        if(i <= b-1){
            swap(arr[0], arr[i]);
            temp_for_b--;
            cout << "before heapify: ";
            printArray(arr, n);
            heapify(arr, temp_for_b, 0);
            cout << "after heapify: ";
            printArray(arr,n);
        }else{
            swap(arr[0], arr[i]);
            cout << "before heapify: ";
            printArray(arr, n);
            heapify(arr, b, 0);
            cout << "after heapify: ";
            printArray(arr,n);
        }

    }
}

// /* A utility function to print array of size n */
 void printArray(int arr[], int n) 
 { 
     for (int i=0; i<n; ++i) 
         cout << arr[i] << " "; 
     cout << "\n"; 
 } 

// Driver program 
int main() 
{ 
    //int arr[] = {11, 12, 13, 5, 6, 7};
    int arr[] = {1,4,5,2,3,7,8,6,10,9};
    int n = sizeof(arr)/sizeof(arr[0]); 
    int b = 2; //b is given by the question;
    heapSort(arr, n, b); 
    printArray(arr, n);
} 
