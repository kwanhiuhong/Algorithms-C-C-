//
//  main.cpp
//  Question5.cpp
//
//  Created by KHH on 21/9/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//

#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node(int x): data(x), next(NULL){}
};

node *purge(node *head, int key){
    //all extra space will only be dynamically created once, so it's constant extra space.
    node *q = head;
    node *keep_previous_node = head;
    node *temp = head;
    //the program runs in O(list.length), so it's linear time
    while(head){
        if(temp->data == key){
            //this is to handle the deletion if the deletion happens at the beginning of the list.
            head = temp->next;
            delete temp;
            temp = head;
            keep_previous_node = temp;
            q = head;
        }else{
            //I use a node pointer(keep_previous_node) to store the node before the deleted node;
            if(head->data == key){
                keep_previous_node -> next = head->next;
                delete head;
                head = keep_previous_node;
            }else{
                keep_previous_node = head;
            }
            head = head->next;
        }
    }
    return q;
}

int main(){
    int data;
    node *head = NULL;
    cout << "Please input the link list and end the input by inputting -1\n";
    do{
        cin >> data;
        if(data!=-1){
            node *p = new node(data);
            node *last = head;
            if(last){
                while(last->next){
                    last = last->next;
                }
                last->next = p;
            }else{
                head = p;
            }
        }
    }while(data!=-1);
    
    int key_to_be_deleted;
    cout << "please input the key you wanna delete\n";
    cin >> key_to_be_deleted;
    cout << "\nHere is the new list\n";
    node *testing = purge(head, key_to_be_deleted);
    while(testing){
        cout << testing->data << endl;
        testing = testing->next;
    }
    cout << "end of result\n\n";
    return 0;
}
