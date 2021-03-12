#include<iostream>
#include<algorithm>
using namespace std;
void mergesort(int array[], int low, int high);
void merge(int a[], int low, int mid, int high);
void printarray(int array[], int size);

void merge(int a[], int low, int mid, int high){
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    
    // Merge the two parts into temp[].
    while (i <= mid && j <= high){
        if (a[i] < a[j]){
            //cout << "left: ";
            temp[k] = a[i];
            //cout << a[i] << ' ';
            k++;
            i++;
        } else {
            //cout << "right: ";
            temp[k] = a[j];
            //cout << a[j] << ' ';
            k++;
            j++;
        }
    }
    //cout << endl;
    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid){
        temp[k] = a[i];
        k++;
        i++;
    }
    // Insert all the remaining values from j to high into temp[].
    while (j <= high){
        temp[k] = a[j];
        k++;
        j++;
    }
    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++){
        a[i] = temp[i-low];
    }
    //printarray(a, high);
}
void mergesort(int array[], int low, int high){
    if(high > low){
        int mid = (low+high)/2;
        mergesort(array, low, mid);
        mergesort(array, mid+1,high);
        merge(array, low, mid, high);
    }
}
void printarray(int array[], int size){
    cout << "Now printing the array\n";
    for(int count = 0; count <= size; count++){
        cout << array[count] << ' ';
    }
    cout << endl;
}
int main(){
    //int array[10] = {4,2,3,9,7,0,83,5,8,6};
    int n = 20000;
    int array[n];
    //int array[10] = {91,88,66,55,45,39,23,12,5,4};
    //cout << "Originally, the array was random order from 1 to 200000\n";
    for(int cnt = 1; cnt <= n; cnt++){
        array[cnt-1] = cnt;
    }
    random_shuffle(array, &array[n-1]);

    mergesort(array, 0, n-1);
    printarray(array, n-1);
    return 0;
}
