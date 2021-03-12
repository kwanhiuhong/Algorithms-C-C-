//
//  main.c
//  6.2數組（質數）
//
//  Created by 關曉康 on 14/7/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//
#include <stdio.h>



int main()
{
    const int maxnumber = 25;
    int isprime[maxnumber];
    int i;
    int x;
    for (i=0; i<maxnumber; i++){
        isprime[i] = 1;
    }
    //for test
    printf("\t");
    for ( i=2; i<maxnumber; i++){
        printf("%d\t",i);
    }
    // for test
    printf("\n");
    // for test
    
    
    for ( x=2; x<maxnumber; x++){
        if ( isprime[x]){
            for ( i=2; i*x<maxnumber; i++){
                isprime[i*x] = 0;
            }
        }
        // for test
        printf("%d\t",x);
        for (i=2; i<maxnumber; i++){
            printf("%d\t",isprime[i]);
        }
        // for test
        printf("\n");
        // for test
    }
    
    
    for ( i=2; i<maxnumber; i++){
        if (isprime[i]){
            printf("%d\t",i);
        }
    }
    printf("\n");
    
    
    return 0;
}
