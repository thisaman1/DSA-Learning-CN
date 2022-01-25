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

void printback(node* head){
    if(head == NULL){
        return;
    }
    printback(head->next);
    cout<<head->data<<" ";
    
    
    
}


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    node* head = takeinput();
	    printback(head);
	}
	
	return 0;
}
