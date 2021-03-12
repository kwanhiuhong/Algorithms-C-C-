//
//  main.c
//  6.1 數組
//
//  Created by 關曉康 on 10/7/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//

#include <stdio.h>
int main()
{
    int x;
    double sum=0;
    int count=0;
    int number[100];
    printf("please enter some numbers and end the program with -1\n");
    scanf("%d",&x);
    
    while (x!=-1){
        number[count]=x;
        //
        {
            int i;
            printf("%d\t",count);
            for(i=0;i<=count;i++){
                printf("%d\t",number[i]);
            }
            printf("\n");
        }
        //
        sum +=x;
        count++;
        scanf("%d",&x);
    }
    if (count>0){
        printf("The average is %f\n",sum/count);
        int i;
        for(i=0;i<count;i++){
            if(number[i]>sum/count){
                printf("%d\n",number[i]);
            }
        }
    }
    return 0;
}
