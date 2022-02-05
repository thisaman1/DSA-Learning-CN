#include<iostream>
using namespace std;
#include "templates.cpp"

int main(){
    pair2<int,int> p1;          //using property of two types
    p1.setX(10);
    p1.setY(20);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;


    pair2<pair2<int,double>,string> p2;             //using property of 3 different datatypes using pair2 template
    p2.setY("abc");
    pair2<int,double>p3;
    p3.setX(30);
    p3.setY(40.5);

    p2.setX(p3);

    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;

}