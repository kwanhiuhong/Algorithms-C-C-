// C Program for counting sort 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>

//#define RANGE 122
//(Maximum achii code of small digits is 122
void printarray(int array[], int n){
    for(int cnt = 0; cnt < n; cnt++){
        printf("%d ", array[cnt]);
    }
    printf("\n");
}
// The main function that sort the given string arr[] in 
// alphabatical order 
void countSort(int arr[], int n, int k)
{ 
	// The output character array that will have sorted arr 
	//char output[strlen(arr)];
    int output[n];
    
	// Create a count array to store count of inidividul 
	// characters and initialize count array as 0 
	//int count[RANGE + 1], i;
	//memset(count, 0, sizeof(count));
    int count[k+1];
    int i;
    for(int cnt = 0; cnt <= k; cnt++){
        count[cnt] = 0;
    }
    
	// Store count of each character 
	for(i = 0; i < n; ++i)
		++count[arr[i]]; 

	// Change count[i] so that count[i] now contains actual 
	// position of this character in output array 
	for (i = 1; i <= k; ++i)
		count[i] += count[i-1]; 

    //printarray(count, k+1);
	// Build the output character array 
	for (i = 0; i < n; ++i)
	{ 
		output[count[arr[i]]-1] = arr[i]; 
		--count[arr[i]]; 
	} 

	 
	//For Stable algorithm
//    for (i = sizeof(arr)-1; i>=0; --i) 
//    { 
//        output[count[arr[i]]-1] = arr[i]; 
//        --count[arr[i]]; 
//    } 
	
//    For Logic : See implementation
//

	// Copy the output array to arr, so that arr now 
	// contains sorted characters 
	for (i = 0; i < n; ++i)
		arr[i] = output[i]; 
}

// Driver program to test above function 
int main() 
{
    int n = 200000;
    int arr[n];
    srand(time(NULL));
    
    int max = 0;
    for(int cnt = 0; cnt < n; cnt++){
        arr[cnt] = rand() %200001;
        if(cnt != 0){
            if(arr[cnt] > max){
                max = arr[cnt];
            }
        }else{
            max = arr[0];
        }
    }
    
//    arr[2] = 21100;
//    if (21100 > max)
//        max = 21100;
    
//    printf("Original array:\n");
//    printarray(arr, n);
//    //char arr[] = "geeksforgeeks";//"applepp";
//    printf("The max now is %d", max);
    
	countSort(arr, n, max);
	//printf("Sorted character array is %s\n", arr);
    printf("\nNow the sorted array: \n");
    printarray(arr, n);
	return 0; 
} 

