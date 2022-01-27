#include<iostream>
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

/*
int printmiddle(node *head,node *tail){
    node* slow = head;
    node* fast = head->next;
    
    while(fast != NULL && fast != tail){
        slow = slow->next;
        fast = fast->next->next;
    }
    //cout<<slow->data;
    return slow->data;
}
*/

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
    int count =0;
    node *head = NULL;
    node *tail = NULL;
    while(data != -1){
        count++;
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        //less efficient method has greater time complexity
        /*else{                                   
            node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;

        }*/
        else{
            tail->next = newNode;
            tail = newNode;
            //or
            //tail = tail->next;
        }
        cin>>data;
    }
    cout<<count<<endl;
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

int count(node *temp){
    int count =0;
    while(temp!= NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

node* mergesort(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node *p = head;
    for(int i=1;i<count(head)/2;i++){
        p = p->next;
    }
    node* head1 = p->next;
    p->next = NULL;

    head = mergesort(head);
    head1 = mergesort(head1);

    return sort(head,head1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        node* head = takeinput();
        print(head);
        node* x = mergesort(head);
        print(x);
    }

}

