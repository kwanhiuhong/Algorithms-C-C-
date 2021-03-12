//
//  main.c
//  4.3分解整數
//
//  Created by 關曉康 on 30/6/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//

#include<stdio.h>
int main()
{
    int number;
    printf("please enter a number\n");
    scanf("%d",&number);
    
    int t=number;
    int digit=1;
    while(t>9){
        t/=10;
        digit *=10;}

    
//    int digit = pow(10,cnt-1);  this is equal to saying calculating 10 to the power 4

    do{
        int d=number/digit;
        printf("%d",d);
        if(digit>9){
            printf(" ");
        }
        number%=digit;
        digit /=10;
    }   while(digit>0);
    
    printf("\n");

    
    return 0;
}
