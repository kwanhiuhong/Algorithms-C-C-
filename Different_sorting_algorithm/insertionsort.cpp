#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
void printarray(int array[], int n){
    for(int cnt = 0; cnt <= n; cnt++){
        cout << array[cnt] << ' ';
    }
    cout << endl;
}
//void insertionsort(int array[], int n){
//    int Output_array[n+1];
//    //Initialize the output array, caused O(n);
//    for(int cnt = 0; cnt <= n; cnt++){
//        Output_array[cnt] = 0;
//    }
//    //insertion sort, caused O(n^2);
//    for(int cnt = 0; cnt <= n; cnt++){
//        if(cnt == 0){
//            Output_array[cnt] = array[cnt];
//        }else{
//            Output_array[cnt] = array[cnt];
//            for(int highest_index = cnt-1; highest_index >= 0; highest_index--){
//                if(Output_array[highest_index+1] < Output_array[highest_index]){
//                    swap(Output_array[highest_index+1], Output_array[highest_index]);
//                }
//            }
//        }
//    }
//    //put the output array into the input array, caused O(n)
//    for(int cnt = 0; cnt <= n; cnt++){
//        array[cnt] = Output_array[cnt];
//    }
//    
//}
void insertionSort(int arr[], int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        j = i-1;
        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
        while (j >= 0 && arr[j] > arr[j+1])
        {
            swap(arr[j], arr[j+1]);
            j--;
        }
    }
}
int main(){
    int Input_array[10];
    for(int cnt = 0; cnt < 10; cnt++){
        Input_array[cnt] = rand()%(10+1);
    }
    cout << "Original array\n";
    printarray(Input_array, 9);
    
    insertionSort(Input_array, 9);
    printarray(Input_array, 9);
    return 0;
}
