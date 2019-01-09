//
//  main.cpp
//  TaskD-Permutation
//
//  Created by KHH on 1/10/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;

long long i;
long long count_for_i = 1;

// surpose n = 4, numbers 1 2 3 4
// how to compute whn i = 13

// observe that
// 6 permutations starting from 1, which are  1, 2 , 3, 4; 1 2 4 3;...
// 6                            2,
// 6                            3
// 6                            4


// go to group 3,

// find 13 - 2*6 = 1-th permutaions for {1 ,2, 4}

long long factorial(long long n){
    long long output = 1;
    if(n==0){
        return 1;
    }
    while(n!=1){
        output*=n;
        n--;
    }
    return output;
}

int main(){
    char question;
    cin >> question;
    long long n;
    cin >> n >> i;
    vector<long long> array;
    for(int count = 1; count <= n; count++){
        array.push_back(count);
    }
    //optimization
    long long size = n-1;
    for(int count = 0;size != 1 && i != 1;count++, size--){
        long long factoria = factorial(size);
        long long each_loop_head;
        if(i%factoria == 0){
            each_loop_head = i/factoria;
        }else{
            each_loop_head = i/factoria + 1;
        }
        array[count] = array[count+each_loop_head-1];
        int increasing_one = 1;
        for(int count2 = count+1;count2 < n;count2++){
            for(int cnt3 = 0; cnt3 <= count; cnt3++){
                if(array[cnt3]==increasing_one){
                    increasing_one++;
                    cnt3 = -1;
                }
            }
            array[count2] = increasing_one;
            increasing_one++;
        }
        
        if(i%factoria == 0){
            i = factoria;
        }else{
            i = i%factoria;
        }
        if(i==2 && i>=factoria){
            int cnt = count+1;
            long long temp = array[cnt];
            array[cnt] = array[cnt+1];
            array[cnt+1] = temp;
            break;
        }
    }

    for(int count = 0; count < array.size(); count++){
        cout << array[count] << ' ';
    }
    cout << endl;
    return 0;
}

