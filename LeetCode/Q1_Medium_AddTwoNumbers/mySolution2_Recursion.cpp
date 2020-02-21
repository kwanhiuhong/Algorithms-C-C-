#include <iostream>
#include <string>
using namespace std;
struct node {
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};

node *convertToLinkedList(string input);
void addTwoNumbers(node* l1, node* l2, node *dummyHead, int carry = 0);
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

//my solution
void addTwoNumbers(node* l1, node* l2, node *dummyHead, int carry){
    if (l1 == NULL && l2 == NULL) return;
    
    int number1 = l1 != NULL ? l1->val : 0;
    int number2 = l2 != NULL ? l2->val : 0;
    int sum = number1 + number2 + carry;
    
    dummyHead -> next = new node(sum % 10);
    
    addTwoNumbers(l1 != NULL ? l1->next : NULL,
                  l2 != NULL ? l2->next : NULL,
                  dummyHead->next, sum/10);
}

int main(){
    string number1;
    string number2;
    cout << "please input the two numbers:" << endl;
    cin >> number1;
    cin >> number2;
    node *head1 = convertToLinkedList(number1);
    node *head2 = convertToLinkedList(number2);
    printList(head1);
    printList(head2);
    
    //your ans here
    node *dummyHead = new node(0);
    addTwoNumbers(head1, head2, dummyHead);
    printList(dummyHead->next);
    return 0;
}
