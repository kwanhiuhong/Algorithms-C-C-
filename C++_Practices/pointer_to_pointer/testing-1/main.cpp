//
//  main.cpp
//  testing-1
//
//  Created by KHH on 25/10/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//

#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
int main(){
    //const int** ptr1 = new int*;
    int **const ptr2 = new int*;
    const int** ptr3 = new const int*;
    const int** ptr4 = new int const*;
    //const int** ptr5 = new int* const;
//    *prt1 = new int;
//    **ptr1 = 1;
    *ptr2 = new int;
    **ptr2 = 2;
    return 0;
}
//using namespace std;
//
//int main () {
//    int  var;
//    int  *ptr = &var;
//    int  **pptr;
//    
//    var = 3000;
//    
//    // take the address of var
//    
//    
//    // take the address of ptr using address of operator &
//    pptr = &ptr;
//    
//    // take the value using pptr
//    cout << "Value of var :" << var << endl;
//    cout << "Value available at *ptr :" << *ptr << endl;
//    cout << "Value available at **pptr :" << *pptr << endl;
//    
//    return 0;
//}
