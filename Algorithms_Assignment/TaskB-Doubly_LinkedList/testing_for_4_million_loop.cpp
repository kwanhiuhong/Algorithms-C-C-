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
    
    int n;
    cin >> n;
    node *head = NULL;
    node *temp_for_store_head = NULL;
    node *temp_for_PreviousNode = NULL;
    for(int count = 0; count < n; count++){
        node *p = new node;
        p->id = count;
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
    //End of the doubly linked list
    
    //    node *temp_head = head;
    //    node *testing = head;
    //    while(testing){
    //        cout << testing->id << ' ';
    //        testing = testing->next;
    //        if(testing->id == temp_head->id){
    //            break;
    //        }
    //    }
    //    cout << endl << endl;
    
    
    
    int array_for_l[n];
    for(int count = 0; count < n; count++){
        array_for_l[count] = count;
    }
    int array_for_l2[n];
    for(int count = 0; count < n; count++){
        array_for_l2[count] = count;
    }
    node *testing = head;
    for(int count = 0; count < n; count++){
//        cout << testing->id << ' ';
        testing = testing->next;
    }
//    cout << endl << endl;
    return 0;
}
