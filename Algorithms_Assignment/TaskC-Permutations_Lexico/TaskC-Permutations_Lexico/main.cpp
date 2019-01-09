//
//  main.cpp
//  TaskC-Permutations_Lexico
//
//  Created by KHH on 29/9/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//
#include<iostream>
#include<vector>
using namespace std;

void perm(vector<int> A, int k, int n){
    if(k==0){
        for(int count = 0; count < n; count++){
            cout << A[count] << " ";
            if((count+1)%(n) == 0){
                cout << endl;
            }
        }
    }else{
        for(int count = 0; count < k; count++){
            int s = n-k;
            int temp;
            temp = A[s];
            A[s] = A[s+count];
            A[s+count] = temp;
            perm(A, k-1, n);
        }
    }
    
}

int main(){
    char question;
    cin >> question;
    int n;
    cin >> n;
    vector<int> array;
    for(int count = 0; count < n; count++){
        int x;
        cin >> x;
        array.push_back(x);
    }
    perm(array, n-1, n);
    return 0;
}
