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

void selectionSort(int arr[], int n){
    for(int count = n; count >= 1; count--){
        int max_index = count;
        for(int cnt = 0; cnt <= count-1; cnt++){
            if(arr[cnt] > arr[max_index]){
                max_index = cnt;
            }
        }
        swap(arr[count], arr[max_index]);
    }
}
int main(){
    int Input_array[10];
    for(int cnt = 0; cnt < 10; cnt++){
        Input_array[cnt] = rand()%(10+1);
    }
    cout << "Original array\n";
    printarray(Input_array, 9);
    
    selectionSort(Input_array, 9);
    printarray(Input_array, 9);
    return 0;
}
