//
//  main.c
//  6.1 The application of Array數組的應用
//
//  Created by 關曉康 on 10/7/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//
#include <stdio.h>
int main()
{
    const int number =10;       //set the size of the array
    int x;
    int count[10];              //define the array
    int i;
    
    for(i=0;i<number;i++){      //
        count[i]=0;             //Initialize the array
    }                           //
    
    printf("please enter some numbers ranging from 0-9\n");
    scanf("%d",&x);
    
    while(x!=-1)
    {
        if(x>=0 && x<=9){
            count[x]++;
        }
        scanf("%d",&x);
    }
    for (i=0;i<number;i++){
        printf("%d:%d\n",i,count[i]);
    }
    
    return 0;
}
