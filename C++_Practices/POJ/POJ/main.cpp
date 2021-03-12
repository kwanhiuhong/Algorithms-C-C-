//
//  main.cpp
//  POJ
//
//  Created by 關曉康 on 3/1/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//  problem 1011-sticks
#include <iostream>
using namespace std;

int find_largest(int *p, int data);
bool sorting(int *p, int data, int cnt, int how_many_groups);

int main(void){
    int data;
    do{
        cin >> data;
        int *p;
        p = new int[data];
        for (int count = 0, sum = 0; count < data; count++){
            cin >> p[count];
            sum += p[count];
            if (data == 1){
                cout << p[0];
                continue;
            }
            if (count == data-1){
                for (int cnt = find_largest(p, data); cnt <= sum; cnt++){
                    if (sum % cnt == 0){
                        
                  //      if (sorting(p, data, cnt, sum/cnt)){}
                //          else continue;
                            
                        cout << cnt;
                        break;
                    }
                    if (cnt == sum) {
                        cout << find_largest(p,data);
                        break;
                    }
                }
            }
        }
        delete[] p;
    } while (data != 0);
    
    return 0;
}
int find_largest(int *p, int data){
    int largest = 0;
    for(int k = 1; k < data; k++){
        if(k == 1) largest = p[k-1];
        if(p[k] > largest){
            largest = p[k];
        }
    }
    return largest;
}
bool sorting(int *p, int data, int cnt, int how_many_groups){
    for(int count = 0; count < data; count++){
        int *replicate = new int[data];
        for(int count1 = 0; count < data; count1++){
            replicate[count1] = p[count1];
        }
        
        
        
        
        for(int count2 = 0; count2 < data; count2++){
            int sum = replicate[count2];
            int checking = 1;
            
            while(checking){
                int count10 = 0;
                for(int count3 = count2+1; count3 < data; count3++){
                    sum += replicate[count3];
                    int check = 0;
                    if (sum == cnt) {
                        check++;
                        break;
                    }
                    if (sum > cnt) {
                        sum -= replicate[count3];
                        continue;
                    }
                    if(count3 == data-1 && check == 0){
                        count2++;
                        count10++;
                    }
                    if(count2 == data-1 && check != how_many_groups){
                        return false;
                    }
                }
            }
        }
        
        
     
        
        
        delete[] replicate;
    }
    return 0;
}

