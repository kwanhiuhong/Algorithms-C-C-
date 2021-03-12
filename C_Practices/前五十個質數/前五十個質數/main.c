//
//  main.c
//  前五十個質數
//
//  Created by 關曉康 on 28/6/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//

#include <stdio.h>
int main()
{
    int x;
    int countprime=0;
    
    
    for (x=2;;x++){
        int i;
        int isprime =1;   //x is a prime number
        for (i=2; i<x ; i++){
            if (x % i ==0){
                isprime=0;
                break;
            }
        }
        if (isprime == 1){
            countprime ++;
            printf("%d\t",x);
            if (countprime % 5==0)
            {
                printf("\n");
            }
            if (countprime == 50){
                goto out;
            }
        }
        
    }
out:
    return 0;
}
