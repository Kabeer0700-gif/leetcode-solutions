#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int val){
        data = val;
        next =  NULL;
    }
};

class List{
    Node* head;
    public:
        List(){
            head = NULL;
        }

        void push_front(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }

            newNode->next = head;
            head = newNode;
        }

        void push_back(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
        }

        void pop_front(){
           if(head){
                Node* temp = head;
                head = temp->next;
                delete temp;
                temp = NULL;
           }else{
            cout<<"List is empty"<<endl;
           }
        }

        void pop_back(){
            if(head == NULL){
                cout<<"List is empty"<<endl;
                return;
            }

            if(head->next == NULL){
                delete head;
                head = NULL;
                return;
            }
            
            Node* temp = head;
            Node* prev = NULL;
            while(temp->next != NULL){
                    prev = temp;
                    temp = temp->next;
                }

            prev->next = NULL;
            delete temp;
           
        }

        void remove_elements(int val){
            Node* dummy = new Node(0);
            Node* temp = head;
            dummy->next = temp;

            Node* prev = dummy;
            
            while(temp != nullptr){
                if(temp->data == val){
                    prev->next = temp->next;

                    Node* toDel = temp;
                    temp = temp->next;
                    delete toDel;
                }else{
                    prev = temp;
                    temp = temp->next;
                }
            }

            head = dummy->next;
            delete dummy;
        }

        //reverse linked list

        void reverse(){
            Node* curr = head;
            Node* prev = NULL;
            Node* next = NULL;
            while(curr != NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
        }

        void display(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

};
int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.display();

    ll.pop_front();
    ll.pop_front();

    ll.display();

    ll.pop_back();

    ll.display();
    
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(5);
    ll.push_front(5);
    
    ll.display();
    ll.remove_elements(5);
    ll.display();

    ll.reverse();
    ll.display();


}