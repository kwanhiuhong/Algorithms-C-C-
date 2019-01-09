//
//  main.cpp
//  TaskB-Doubly_LinkedList
//
//  Created by KHH on 3/10/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//
#include<iostream>
using namespace std;
class node{
public:
    int id;
    int index;
    node *previous;
    node *next;
};

int main(){
    //Here is the doubly linked list
    char input_of_questions;
    cin >> input_of_questions;
    int n;
    cin >> n;
    node *head = NULL;
    node *temp_for_store_head = NULL;
    node *temp_for_PreviousNode = NULL;
    
    for(int count = 0; count < n; count++){
        node *p = new node;
        cin >> p->id;
        p->index = count;
       
        if(head){
            head->next = p;
            head = head->next;
            head->previous = temp_for_PreviousNode;
            temp_for_PreviousNode = p;
        }else{
            head = p;
            temp_for_store_head = head;
            temp_for_PreviousNode = head;
        }
        
    }
    head->next = temp_for_store_head;
    temp_for_store_head->previous = head;;
    head = temp_for_store_head;
    //End of initializing the doubly linked list

    int array_for_l[n];
    for(int count = 0; count < n; count++){
        cin >> array_for_l[count];
    }
    
    int for_loop_max = n;
    for(int count = 0; count < for_loop_max; count++){
        int l = array_for_l[head->index];
        if(n==2){
            if(l%n == 1 || l%n == -1){
                cout << head->id << endl;
                break;
            }else{
                cout << (head->previous)->id << endl;
                break;
            }
        }
        if(l%n == 0){
            node *p = head;
            (head->previous)->next = head->next;
            (head->next)->previous = head->previous;
            head = head->next;
            delete p;
            n--;
            continue;
        }else if(l%n > 0){
            
            //this for loop below is too time consuming
            for(int count = 0; count < l%n; count++){
                head = head->next;
            }
            
            node *p = head;
            (head->previous)->next = head->next;
            (head->next)->previous = head->previous;
            head = head->next;
            delete p;
            n--;
            continue;
        }else if(l%n < 0){
            
            //this for loop below is too time consuming
            for(int count = 0; count < abs(l%n); count++){
                head = head->previous;
            }
            
            node *p = head;
            (head->previous)->next = head->next;
            (head->next)->previous = head->previous;
            head = head->next;
            delete p;
            n--;
            continue;
        }
    }
    return 0;
}
