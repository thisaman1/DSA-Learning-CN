#include<iostream>
using namespace std;

class fraction{

    int numerator;
    int denominator;

    public:

    fraction(int numerator,int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getnumerator(){
        return numerator;
    }
    int getdenominator(){
        return denominator;
    }

    void setnumerator(int numerator){
        this->numerator = numerator;
    }
    void setdenominator(int denominator){
        this->denominator = denominator;
    }

    void display(){
        cout<<numerator<<" / "<<denominator<<endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(this->numerator,this->denominator);
        for(int i=1; i<=j; i++){
            if(this->numerator%i == 0 && this->denominator%i == 0){
                gcd = i;
            }
        }
        this->numerator = this->numerator/gcd;
        this->denominator = this->denominator/gcd;
    }

    void add(fraction const &f2){
        int lcm = this->denominator*f2.denominator;
        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = x*this->numerator + y*f2.numerator;

        numerator = num;
        denominator = lcm;

        simplify();
    }

    void multiply(fraction const &f2){
        numerator = numerator*f2.numerator;
        denominator = denominator*f2.denominator;

        simplify();
    }
};

int main(){

    fraction f1(10,2);
    fraction f2(24,4);

    f1.display();
    f2.display();

    f1.add(f2);
    f1.display();
    f2.display();

    return 0;
}