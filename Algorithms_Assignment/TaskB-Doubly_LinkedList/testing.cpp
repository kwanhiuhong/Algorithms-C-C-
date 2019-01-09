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
    int for_loop_max = n;
    for(int count = 0; count < for_loop_max; count++){
        int l = array_for_l[head->index] % 10;
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
            
//            node *testing2 = head;
//            while(testing2){
//                cout << testing2->id << ' ';
//                testing2 = testing2->next;
//                if(testing2->id == head->id){
//                    break;
//                }
//            }
//            cout << endl << endl;
            
            continue;
        }else if(l%n > 0){
            for(int count = 0; count < l%n; count++){
                head = head->next;
            }
            node *p = head;
            (head->previous)->next = head->next;
            (head->next)->previous = head->previous;
            head = head->next;
            delete p;
            n--;
            
//            node *testing2 = head;
//            while(testing2){
//                cout << testing2->id << ' ';
//                testing2 = testing2->next;
//                if(testing2->id == head->id){
//                    break;
//                }
//            }
//            cout << endl << endl;
            
            continue;
        }else if(l%n < 0){
            for(int count = 0; count < abs(l%n); count++){
                head = head->previous;
            }
            node *p = head;
            (head->previous)->next = head->next;
            (head->next)->previous = head->previous;
            head = head->next;
            delete p;
            n--;
            
//            node *testing2 = head;
//            while(testing2){
//                cout << testing2->id << ' ';
//                testing2 = testing2->next;
//                if(testing2->id == head->id){
//                    break;
//                }
//            }
//            cout << endl << endl;
            
            continue;
        }
    }
    return 0;
}
