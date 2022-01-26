#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* sort(node* first,node* second){
    node* head = NULL;
    node* tail = NULL;
    while(first != NULL && second != NULL){
        
        if(head == NULL){
            if(first->data<second->data){
                head = first;
                tail = first;
                first = first->next;
            }
            else{
                head = second;
                tail = second;
                second = second->next;
            }
        }
        else if(first->data < second->data){
            tail->next = first;
            tail = first;
            first = first->next;;
            
        }
        else{
            tail->next = second;
            tail = second;
            second = second->next;
            
        }
    }
    if(first != NULL){
        tail->next = first;
        //first = first->next;
    }
    else if(second != NULL){
        tail->next = second;
        //second = second->next;
    }
    return head;
}

node* takeinput(){
    int data;
    cin>>data;
    node *head = NULL;
    node *tail = NULL;
    while(data != -1){
        node* newnode = new node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        node* h1 = takeinput();
        node* h2 = takeinput();
        node* head = sort(h1,h2);
        print(head);
    }
    return 0;
}