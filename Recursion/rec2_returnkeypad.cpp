#include<bits/stdc++.h>
using namespace std;
string str[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int input,string output[]){
    if(input==0){
        output[0] = "";
        return 1;
    }
    int lastdigit = input%10;
    input = input/10;
    int smalloutput = keypad(input,output);
    for(int i=0;i<str[lastdigit-2].size()*smalloutput;i++){
        output[smalloutput+i] = output[i%smalloutput];
    }
    int i=0;
    for(int j=0;j<str[lastdigit-2].size();j++){
        for(;i<smalloutput*(j+1);i++){
            output[i] = output[i] + str[lastdigit-2][j];
        }
    }
    return smalloutput*str[lastdigit-2].size();
}
int main(){
    int input;
    cin>>input;
    int temp = input;
    int no_of_digit = 0;
    while(temp != 0){
        no_of_digit++;
        temp = temp/10;
    }
    int noofsubsequence = pow(4,no_of_digit);
    string* output = new string[noofsubsequence];

    int value = keypad(input,output);

    for(int i=0;i<value;i++){
        cout<<output[i]<<"  ";
    }
    return 0;

}