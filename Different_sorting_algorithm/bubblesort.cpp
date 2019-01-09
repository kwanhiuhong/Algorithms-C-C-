#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n = 50000;
    int array[n];
    //int array[10] = {91,88,66,55,45,39,23,12,5,4};
    cout << "Originally, the array was random order from 1 to 200000\n";
    for(int cnt = 1; cnt <= n; cnt++){
        array[cnt-1] = cnt;
    }
    random_shuffle(array, &array[n-1]);
    int counter_for_bubblesort1 = 0;
    for(int count = 0; count < n; count++){
        for(int cnt = count + 1; cnt < n; cnt++){
            if(array[count] > array[cnt]){
                int temp = array[count];
                array[count] = array[cnt];
                array[cnt] = temp;
                counter_for_bubblesort1++;
            }
        }
    }
//    for(int count = 0; count < n; count++){
//        cout << array[count] << ' ';
//    }
//    cout << endl;
//    cout << "Total number of count for bubble sort 1 is " << counter_for_bubblesort1 << endl;
//    
//    
    
//    //int array2[10] = {91,88,66,55,45,39,23,12,5,4};
//    int array2[10] = {45,23,12,55,88,91,4,66,39,5};
//
//    
//    int counter_for_bubblesort2 = 0;
//    for(int count = 10; count >= 2; count--){
//        for(int cnt = 0; cnt < count-1; cnt++){
//            if(array2[cnt] > array2[cnt+1]){
//                int temp = array2[cnt];
//                array2[cnt] = array2[cnt+1];
//                array2[cnt+1] = temp;
//                counter_for_bubblesort2++;
//            }
//        }
//    }
//    for(int count = 0; count < 10; count++){
//        cout << array2[count] << ' ';
//    }
//    cout << endl;
//    cout << "Total number of count for bubble sort 2 is " << counter_for_bubblesort2 << endl;
    return 0;
}
