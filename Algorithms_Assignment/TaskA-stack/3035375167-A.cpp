//
//  main.cpp
//  Question6
//
//  Created by KHH on 22/9/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//
#include<iostream>
#include<string>
using namespace std;

int global_index_for_top_of_stack = -1;

void push_stack(int stack[], int y);
int pop_stack(int stack[]);
int top_stack(int stack[]);

int main(){
    char x;
    cin >> x;
    int number_of_sequence;
    cin >> number_of_sequence;
    int stack[number_of_sequence];
    
    int pushseq[number_of_sequence];
    for(int count = 0; count < number_of_sequence; count++){
        cin >> pushseq[count];
    }
    
    int popseq[number_of_sequence];
    for(int count = 0; count < number_of_sequence; count++){
        cin >> popseq[count];
    }
    
    string storing_output_array[number_of_sequence*2];
    int index_output_array = 0;
    
    for(int cnt_push = 0, cnt_pop = 0; cnt_push <= number_of_sequence-1 || cnt_pop <= number_of_sequence-1;){
        if(global_index_for_top_of_stack==-1){
            push_stack(stack, pushseq[cnt_push]);
            storing_output_array[index_output_array] = "push "+to_string(pushseq[cnt_push]);
            index_output_array++;
            cnt_push++;
        }else if(popseq[cnt_pop] == top_stack(stack)){
            pop_stack(stack);
            storing_output_array[index_output_array] = "pop ";
            index_output_array++;
            cnt_pop++;
        }else if(cnt_push >= number_of_sequence && top_stack(stack) != popseq[cnt_pop]){
            cout << "NO\n";
            break;
        }else{
            push_stack(stack, pushseq[cnt_push]);
            storing_output_array[index_output_array] = "push "+to_string(pushseq[cnt_push]);
            index_output_array++;
            cnt_push++;
        }
    }
    
    if(global_index_for_top_of_stack == -1){
        for(int count = 0; count < number_of_sequence*2; count++){
            cout << storing_output_array[count] << endl;
        }
    }
    
//    cout << "\nThe stack now contains the following\n";
//    for(int count = 0; count <= global_index_for_top_of_stack; count++){
//        cout << stack[count] << " ";
//    }
    return 0;
}

void push_stack(int stack[], int y){
    stack[global_index_for_top_of_stack+1] = y;
    global_index_for_top_of_stack ++;
}
int pop_stack(int stack[]){
    int x = stack[global_index_for_top_of_stack];
    global_index_for_top_of_stack --;
    return x;
}
int top_stack(int stack[]){
    int temp = pop_stack(stack);
    push_stack(stack, temp);
    return temp;
}


