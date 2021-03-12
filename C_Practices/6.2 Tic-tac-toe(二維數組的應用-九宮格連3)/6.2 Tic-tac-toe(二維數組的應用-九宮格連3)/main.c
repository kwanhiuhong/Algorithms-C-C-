//
//  main.c
//  6.2 Tic-tac-toe(二維數組的應用-九宮格連3)
//
//  Created by 關曉康 on 14/7/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
//

#include <stdio.h>
int main()
{
    const int size=3;
    int board [size][size];
    int i,j;
    int numofx;
    int numof0;
    int result = -1;  //-1 no one wins.   1 = x wins    0= O wins
    
    // input the matrix
    for (i=0; i<size; i++){
        for ( j=0; j<size; j++){
            scanf ("%d",&board[i][j]);
        }
    }
    
    // check 行
    for ( i=0; i<size && result ==-1; i++){
        numof0 = numofx = 0;
        for( j=0; j<size ; j++){
            if ( board [i][j] ==1){
                numofx ++;
            }   else {
                numof0 ++;
            }
        }
        if ( numof0 == size ){
            result = 0;
        } else if (numofx == size ){
            result =1 ;
        }
    }
    
    
    
    // check 列
    if (result == -1){
        for ( j=0; j<size && result ==-1; j++){
            numof0 = numofx = 0;
            for( i=0; i<size ; i++){
                if ( board [i][j] ==1){
                    numofx ++;
                }   else {
                    numof0 ++;
                }
            }
            if ( numof0 == size ){
                result = 0;
            } else if (numofx == size ){
                result =1 ;
            }
        }
    }
    
    
    // check對角線
    if (result == -1){
        numof0 = numofx = 0;
        for( i=0; i<size ; i++){
            if ( board [i][i] ==1){
                numofx ++;
            }   else {
                numof0 ++;
            }
        }
        if ( numof0 == size ){
            result = 0;
        } else if (numofx == size ){
            result =1 ;}
    }
    
    if (result == -1){
        numof0 = numofx = 0;
        for( i=0; i<size ; i++){
            if ( board [i][size-i-1] ==1){
                numofx ++;
            }   else {
                numof0 ++;
            }
        }
        
    }
    
    if ( result == -1){
        printf("no one wins\n");
    } else if( result ==1){
        printf("x wins\n");
    }   else if(result == 0){
        printf("O wins\n");
    }
    return 0;
}
