#include <iostream>
#include <string>
using namespace std;
struct node {
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};

node *convertToLinkedList(string input);
node *addTwoNumbers(node* l1, node* l2, int carry);
void printList(node *head);


void printList(node *head){
    cout << "the linked list contains: ";
    while(head){
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

node *convertToLinkedList(string input){
    node *dummyHead = new node(0);
    node *head = dummyHead;
    for(int cnt = 0; cnt < input.length(); cnt++){
        node *p = new node(input[cnt] - '0');
        head->next = p;
        head = head->next;
    }
    return dummyHead->next;
}

//In this answer I stick strictly to the default function header by leetcode
//first define a global variable called dummyHead, same as the class public variable
node *addTwoNumbers(node* l1, node* l2, int carry = 0){
    if (l1 == NULL && l2 == NULL){
        if (carry > 0) return new node(carry);
        return NULL;
    }
    
    int number1 = l1 != NULL ? l1->val : 0;
    int number2 = l2 != NULL ? l2->val : 0;
    int sum = number1 + number2 + carry;
    node *head = new node(sum % 10);
    head->next = addTwoNumbers(l1 != NULL ? l1->next : NULL,
                                    l2 != NULL ? l2->next : NULL,
                                    sum / 10);
    return head;
}

int main(){
    string number1;
    string number2;
    cout << "please input the two numbers:" << endl;
    cin >> number1;
    cin >> number2;
    node *head1 = convertToLinkedList(number1);
    node *head2 = convertToLinkedList(number2);
    
    //your ans here
    node *head = addTwoNumbers(head1, head2);
    printList(head);
    return 0;
}
