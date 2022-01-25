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
    int n;
    cin>>n;
    node* temp = head;
    node* newhead = NULL;
    
    for(int i=0;i<count-1-n;i++){
        temp = temp->next;
    }
    newhead = temp->next;
    temp->next = NULL;
    
    tail->next = head;
    
    return newhead;
}

void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    node* head = takeinput();
	    print(head);
	}
	
	return 0;
}
