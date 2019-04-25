//
//  main.cpp
//  quick_sort
//
//  Created by Peter on 11/8/18.
//  Copyright © 2018 Peter. All rights reserved.
//

#include <iostream>

using namespace std;

int partition(int * arr, int p ,int r);
void quicksort(int * arr, int p ,int r);
void kthsmallest(int * arr, int p ,int r, int k);

int main(int argc, const char * argv[]) {

    int array[7] = {1,10,3,9,8,4,5};
    // {1,10,3,9,8,4,5};
    // {1,3,4,5,8,9,10}
    cout << endl;
    //quicksort(array, 0, 6);
    kthsmallest(array, 0, 6, 1);
//    for(int j=0; j<7;j++){
//
//        cout << "j is " << array[j] << endl;
//    }
//
    return 0;
}

int partition(int * arr, int p ,int r){
    
    int x = arr[r];
    int i = p - 1; // at the start i will be -1
    for(int j = p; j<r; j++){
        if(arr[j] <= x){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp2 = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp2;
    return i+1;
}
void kthsmallest(int * arr, int p ,int r, int k){
    int x = arr[r];
    int i = p - 1; // at the start i will be -1
    for(int j = p; j<r; j++){
        if(arr[j] <= x){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp2 = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp2;
    
    if(i == k-1){
        cout << arr[i] << " is the kth smallest" << endl;
    }else if(i < k-1 ){
        kthsmallest(arr, i+2, r , k);
    }else{
        kthsmallest(arr, p, i , k);
    }
    
}
void quicksort(int * arr, int p ,int r){
    cout << "p is " << p << endl;
    if(p<r){
        int q = partition(arr, p , r);
        cout << "q is " << q << endl;
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
    
}
