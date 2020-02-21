#include <iostream>
#include <string>
using namespace std;
struct node {
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};

node *convertToLinkedList(string input);
node* addTwoNumbers(node* l1, node* l2);
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

node* addTwoNumbers(node* l1, node* l2){
    node *head = NULL;
    node *tempHead = head;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL){
        int sum = 0;
        node *temp = new node(0);
        
        if (l1 != NULL && l2 != NULL){
            sum += (l1 -> val + l2 -> val + carry);
            if (sum > 9){
                carry = sum / 10;
                sum = sum % 10;
            } else {
                carry = 0;
            }
            temp -> val = sum;
            if (tempHead == NULL){
                tempHead = temp;
                head = tempHead;
            } else {
                tempHead -> next = temp;
                tempHead = tempHead->next;
            }
        } else {
            if (l1 != NULL){
                sum += (l1 -> val + carry);
                if (sum > 9){
                    carry = sum / 10;
                    sum = sum%10;
                } else {
                    carry = 0;
                }
                temp -> val = sum;
                if (tempHead == NULL){
                    tempHead = temp;
                    head = tempHead;
                } else {
                    tempHead -> next = temp;
                    tempHead = tempHead->next;
                }
            }
            if (l2 != NULL){
                sum += (l2 -> val + carry);
                if (sum > 9){
                    carry = sum / 10;
                    sum = sum%10;
                } else {
                    carry = 0;
                }
                temp -> val = sum;
                if (tempHead == NULL){
                    tempHead = temp;
                    head = tempHead;
                } else {
                    tempHead -> next = temp;
                    tempHead = tempHead->next;
                }
            }
        }
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    if (carry > 0){
        tempHead -> next = new node(carry);
    }
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
    printList(head1);
    printList(head2);
    
    //your ans here
    node *ans = addTwoNumbers(head1, head2);
    printList(ans);
    return 0;
}

