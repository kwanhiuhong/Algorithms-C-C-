#include<iostream>
#include<algorithm>
using namespace std;
void printarray(int array[], int n){
    for(int cnt = 0; cnt <= n; cnt++){
        cout << array[cnt] << ' ';
    }
    cout << endl;
}

void heapify(int arr[], int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
    //all the process below are to make sure that the root is the largest, the recursive function at
    //the bottom is the push down the root or to fix the affected sub tree.
    //If left child is larger than root
    //like here is     8
    //              /      \
    //             12       19
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    // If largest is not root
    if (largest != i){
        swap(arr[i], arr[largest]);
        //after that the sub tree now is  19
        //                              /   \
        //                              12   8
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    } 
}

void heapSort(int arr[], int n){
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--){
        // Move current root to end, move the largest one to the end and reduce the size of heap by 1
        //this is to make sure the array sorted in ascending order.
        swap(arr[0], arr[i]);
        
        // as it swaps with the index 0, we have put 0 as i in the heapify below
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main(){
    int n = 200000;
    int Input_array[n];
    for(int cnt = 0; cnt < n; cnt++){
        Input_array[cnt] = rand()%(n+1);
    }
//    cout << "Original array\n";
//    printarray(Input_array, 199999);
    
    heapSort(Input_array, n);
    printarray(Input_array, n-1);
    return 0;
}
