#include<bits/stdc++.h>
using namespace std;
string str[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void subs(int input,string output){
    if(input == 0){
        cout<<output<<",";
        return;
    }
    int lastdigit = input%10;
    input = input/10;
    int check = str[lastdigit-2].size();
    if(check ==4){
        subs(input,str[lastdigit-2][0]+output);
        subs(input,str[lastdigit-2][1]+output);
        subs(input,str[lastdigit-2][2]+output);
        subs(input,str[lastdigit-2][3]+output);
    }
    else{
        subs(input,str[lastdigit-2][0]+output);
        subs(input,str[lastdigit-2][1]+output);
        subs(input,str[lastdigit-2][2]+output);
    }

}
int main(){
    int input;
    cin>>input;
    string output = "";
    subs(input,output);
    return 0;
}