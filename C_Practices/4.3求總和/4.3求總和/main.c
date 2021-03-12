//
//  main.c
//  4.3求總和
//
//  Created by 關曉康 on 30/6/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//
#include<stdio.h>
int main()
{
    int n;
    int j=1;
    double sum=0;
    printf("please enter a number so that we can calculate the sum of 1-1/2+1/3-...+/-1/n\n");
    scanf("%d",&n);
    int sign=1;
    
    for(j=1;j<=n;j++)
    {
        sum += sign*1.0/j;
        sign = -sign;
    }
    printf("sum is %f\n",sum);
    
    return 0;
}

