#include<bits/stdc++.h>
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
    //cout<<count<<endl;
    return head;
}
node* Insertnode(node* head, int i,int data){
    int count =0;
    node* temp = head;
    node *newnode = new node(data);
    if(i==0){
        newnode->next = head;
        head =newnode;
        return head;
    }
    while(temp != NULL && count<i-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

node* Insertnode_rec(node*head,int i,int data){
    if(head == NULL){
        return head;
    }

    if(i==0){
        node* newnode = new node(data);
        newnode->next = head;
        head = newnode;
    }
    node* temp = Insertnode_rec(head->next,i-1,data);
    head->next = temp;
    return head;
}

node* deletenode(node* head,int i){
    int count =0;
    node* temp = head;
    if(i==0){
        head = temp->next;
        return head;
    }
    while(temp != NULL && count<i-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        node*a = temp->next;
        temp->next = a->next;
        delete a;
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

int count(node *temp){
    int count =0;
    while(temp!= NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

int main(){

    node *head = takeinput();
    print(head);
    cout<<count(head)<<endl;
    /*
    int i,data;
    cin>>i>>data;
    //head = Insertnode(head,i,data);
    //head = deletenode(head,i);
    head = Insertnode_rec(head,i,data);
    print(head);
    
    //stastically
    node n1(1);
    node *head = &n1;
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);

    //dynamically

    node *n6 = new node(6);
    node *head1 = n6;
    node *n7 = new node(7);
    node *n8 = new node(8);

    n6->next = n7;
    n7->next = n8;

    print(head1);*/

    return 0;

}