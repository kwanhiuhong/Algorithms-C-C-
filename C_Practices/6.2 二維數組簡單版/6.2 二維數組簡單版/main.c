//
//  main.c
//  6.2 二維數組簡單版
//
//  Created by 關曉康 on 14/7/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//

#include <stdio.h>
int main()
{
    int a[3][5];
    int i,j;
    
    for ( i=0; i<3; i++){
        for ( j=0; j<5; j++){
            a[i][j] = i*j;
            printf("%d\t",i*j);
        }
        printf("\n");
    }
    
    return 0;
}
