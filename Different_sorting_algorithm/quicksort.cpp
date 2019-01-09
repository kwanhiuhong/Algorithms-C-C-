#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void printarray(int array[], int n){
    for(int cnt = 0; cnt <= n; cnt++){
        cout << array[cnt] << ' ';
    }
    cout << endl;
}
int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = low - 1;
    for(int j = low; j <= high; j++){
        if(array[j] < pivot){
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1], array[high]);
    return i+1;
}
//actually the randomized quick_sort's code can be incorporated into the quicksort function in order to reduce the time of function call.
int randomized_partition(int array[], int low, int high){
    srand(time(0));
    int i = low + rand()%(high-low);
    swap(array[high], array[i]);
    return partition(array, low, high);
}
void quicksort(int array[], int low, int high){
    if(high > low){

        //here if you with to use randomized quicksort, you call randomized_quicksort(), otherwise you can quicksort();
        int pi = randomized_partition(array, low, high);
        quicksort(array, low, pi-1);
        quicksort(array, pi+1, high);
    }
}
int main(){
    int n = 200000;
    //int array[10] = {2,3,51,1,9,6,5,20,0,7};
    
    int array[n];
    for(int cnt = 1; cnt <= n; cnt++){
        array[cnt-1] = cnt;
    }
    //this is to randomly distribute all the elements within the array.
    random_shuffle(array, &array[n-1]);
    
    quicksort(array, 0, n-1);
    printarray(array, n-1);
    return 0;
}


//why we use randomized quick sort??? Because if we don't use randomized quicksort,
//for those arrays which are already sorted, it took O(n^2) to complete the sorting
//if we pick the pivot at the end or at the beginning.
//However, using randomized quicksort, we actually get the expected value/average case of the quicksort, that is O(nlogn), which is much faster and secure. (However, it doesn't mean that its worst case is O(nlogn), just that now it's more rare to encounter the worst case if we use the randomized one)
//for the difference, you can try to time the difference for using randomized quick sort on sorted array and unsorted array vs picking pivot either at the end or at the beginning to sort already sorted array and not sorted array. Huge difference!
