//
//  main.cpp
//  POJ2828
//
//  Created by 關曉康 on 4/1/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//

#include<iostream>
using namespace std;
int main(){
    int row, colum;
    cin >> row >> colum;
    int **array;
    array = new int*[row];
    for(int count = 0; count < row; count++){
        array[count] = new int[colum];
    }
    for(int cnt1 = 0; cnt1 < row; cnt1++){
        for(int cnt2 = 0; cnt2 < colum; cnt2++){
            cin >> array[cnt1][cnt2];
        }
    }
    
    
    for(int count = 0; count < colum; count++){
        delete[] array[count];
    }
    delete[] array;
    return 0;
}
