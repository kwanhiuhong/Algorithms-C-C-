// C Program for counting sort 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

    int output[n];

    int count[k+1];
    int i;
    for(int cnt = 0; cnt <= k; cnt++){
        count[cnt] = 0;
    }
    
	for(i = 0; i < n; ++i)
		++count[arr[i]]; 

	for (i = 1; i <= k; ++i)
		count[i] += count[i-1]; 

	for (i = 0; i < n; ++i)
	{ 
		output[count[arr[i]]-1] = arr[i]; 
		--count[arr[i]]; 
	} 

	for (i = 0; i < n; ++i)
		arr[i] = output[i]; 
}
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

	countSort(arr, n, max);
	//printf("Sorted character array is %s\n", arr);
    printf("\nNow the sorted array: \n");
    printarray(arr, n);
	return 0; 
}
