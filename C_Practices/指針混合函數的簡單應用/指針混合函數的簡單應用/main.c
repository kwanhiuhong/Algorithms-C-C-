//
//  main.c
//  指針混合函數的簡單應用
//
//  Created by 關曉康 on 27/7/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//
#include<stdio.h>

void function(int *p);

int main(void)
{
    int i=6;
    printf("&i=%p\n",&i);
    function(&i);
    
    
    return 0;
}

void function(int *p)
{
    printf(" p=%p\n",p);
}
