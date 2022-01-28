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

class address{
    public:

    node* head;
    node* tail;
};

node* reverseLL(node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }

    node* smallans = reverseLL(head->next);
    node* temp = smallans;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;

    return smallans;
}

address reverseLL_2(node* head){
    if(head == NULL || head->next == NULL){
        address ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    address smallans = reverseLL_2(head->next);

    smallans.tail->next = head;
    head->next = NULL;

    address ans;
    ans.head = smallans.head;
    ans.tail = head;

    return ans;
}

node* reverseLL_better(node* head){
    return reverseLL_2(head).head;
}

node* reverseLL_3(node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }

    node* smallans = reverseLL_3(head->next);
    node* tail = head->next;
    
    tail->next = head;
    head->next = NULL;

    return smallans;
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
    //cout<<count<<endl;
    return head;
}

void print(node*head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    node* head = takeinput();
    node* rev = reverseLL_3(head);
    print(rev);

    return 0;
}