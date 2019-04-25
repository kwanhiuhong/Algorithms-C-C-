//
//  main.cpp
//  testing
//
//  Created by 關曉康 on 11/12/2017.
//  Copyright © 2017年 關曉康. All rights reserved.
#include<iostream>
using namespace std;

int gcd(int x, int y){
    if (y>x){
        int temp = x;
        x = y;
        y = temp;
    }
    int y_new = y;
    for(int i = 1; x>=y_new; i++){
        y_new = y*i;
    }
    y_new = y_new - y;
    int d = x - y_new;
    if(d==0){
        return y;
    }
    cout << y <<" "<< d << endl;
    return gcd(y,d);
}


int main(){
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;;
    return 0;
}
