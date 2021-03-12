//
//  main.cpp
//  Fibonacci_sequence_recursion
//
//  Created by 關曉康 on 21/4/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//

#include <iostream>
using namespace std;

int fib(int x) {
    if (x == 0)
        return 0;
    
    if (x == 1)
        return 1;
    
    return fib(x-1)+fib(x-2);
}

int main(){
    int x;
    cin >> x;
    cout << fib(x) << endl;
    return 0;
}
