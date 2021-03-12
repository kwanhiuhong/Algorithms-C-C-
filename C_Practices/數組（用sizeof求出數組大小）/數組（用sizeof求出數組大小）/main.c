//
//  main.c
//  數組（用sizeof求出數組大小）
//
//  Created by 關曉康 on 12/7/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//

#include <stdio.h>
int main()
{
    int array[]={3,4,4,5,67,76,67};
    int i;
    for (i=0;i<sizeof(array)/sizeof(array[5]);i++){
        printf("%d\n",array[i]);
    }
    
    
    
    return 0;
}
