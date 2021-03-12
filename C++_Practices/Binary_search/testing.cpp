#include<iostream>
#include<cstdlib>
using namespace std;

void Binary_search(int array[], int low, int high, int key);
int main(){
    srand(time(NULL));
    rand();
    int array[20];
    for(int count = 0; count < 20; count++){
        array[count] = rand()%20;
    }
    for(int count = 0; count < 20; count++){
        for(int count2 = count+1; count2 < 20; count2++){
            if(array[count] > array[count2]){
                int temp = array[count];
                array[count] = array[count2];
                array[count2] = temp;
            }
        }
    }
    for(int count = 0; count < 20; count++){
        cout << array[count] << " ";
    }
    cout << endl;
    Binary_search(array, 0, 20, 15);
    return 0;
}
void Binary_search(int array[], int low, int high, int key){
    while(high >= low){
        int mid = (high+low)/2 - 1;
        if(key == array[mid]){
            cout << "Found, it's in position" << mid << ". The key found is " << array[mid] << endl;
            goto end;
        }
        if(key > array[mid]){
            low = mid + 1;
        }
        if(key < array[mid]){
            high = mid - 1;
        }
    }
    cout << "not found\n";
    goto end;
end:
    cout << "\n";
}
