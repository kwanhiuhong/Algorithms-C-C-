//
//  main.c
//  HW3_C
//
//  Created by KHH on 19/11/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int key;
    struct node *next;
};

typedef struct node Node;

// Display the list
void printList(Node *head_ref) {
    // Please implement this function
    Node *temp_head = head_ref;
    printf("[ ");
    while(temp_head){
        printf("%d ", temp_head->data);
        temp_head = temp_head->next;
    }
    printf("]");
}

// Insert data into a sorted list
void sortedInsert(Node **head_ref, int data)
{
    Node *temp_head = *head_ref;
    if(temp_head == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->key = data;
        temp->next = NULL;
        *head_ref = temp;
    }else{
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->next = NULL;
        new_node->key = data;
        new_node->data = data;
        while(temp_head){
            //insert at the beginning
            if(data < temp_head->key){
                new_node->next = (*head_ref);
                (*head_ref) = new_node;
                break;
            }
            //insert at the end
            if(data >= temp_head->key && temp_head->next == NULL){
                temp_head->next = new_node;
                break;
            }
            //insert at the end
            else if(data >= temp_head->key && data < temp_head->next->key){
                new_node->next = temp_head->next;
                temp_head->next = new_node;
                break;
            }
            temp_head = temp_head->next;
        }
    }
    // Please implement this function
}

// Reverse nodes in a linked list
void reverse(Node **head_ref) {
    Node *current = *head_ref;
    Node *previous = NULL, *next = NULL;
    
    while (current != NULL)
    {
        // Store next
        next = current->next;
        
        // Reverse current node's pointer
        current->next = previous;
        
        // Move pointers one position ahead.
        previous = current;
        current = next;
    }
    *head_ref = previous;
}

// Main program
void main() {
    int n;
    Node *head = NULL;
    //Node *current = NULL;
    //printf("%p", &head);
    //n = number of elements that the list contain
    scanf("%d", &n);
    for (int i = 0; i < n;  i++)
    {
        int x;
        scanf("%d", &x);
        sortedInsert(&head, x);
    }
    
    printf("Original List: ");
    printList(head);
    
    reverse(&head);
    printf("\nList after reversing the data: ");
    printList(head);
    printf("\n");
}
