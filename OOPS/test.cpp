#include<iostream>
#include<string.h>
using namespace std;

/*class student{
    
    int age;
    public:

    char *name;

    student(int age,char *name){
        this -> age = age;
        this -> name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    student(student const &s){
        this->age = s.age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name,s.name);
    }
    void display(){
        cout<<age<<" "<<name<<endl;
    }
};*/

int main(){
    /*char name[] = "abcd";
    student s1(20,name);
    s1.display();

    student s2(s1);
    s2.name[0] = 'f';

    s1.display();
    s2.display();*/

    string a;
    cin>>a;
    int count=0;

    for(int i=0;a[i]!=' ';i++){
        count++;
    }
    



}