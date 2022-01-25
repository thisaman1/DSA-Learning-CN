#include <iostream>
using namespace std;
bool haspath_helper(int **input,int n,int **solution,int x,int y){
    if(x== n-1 && y== n-1){
        return true;
    }

    if(x<0 || y<0 || x>=n || y>=n || solution[x][y]== 1 || input[x][y]== 0){
        return false;
    }

    if(haspath_helper(input,n,solution,x,y-1)){
        return true;
    }
    if(haspath_helper(input,n,solution,x-1,y)){
        return true;
    }
    if(haspath_helper(input,n,solution,x,y+1)){
        return true;
    }
    if(haspath_helper(input,n,solution,x+1,y)){
        return true;
    }
    solution[x][y] = 0;
    return false;

}

bool haspath(int** input,int n){
    int **solution;
    for(int i=0;i<n;i++){
        solution[i] = new int[n];
        for(int j=0;j<n;j++){
            solution[i][j] = 0;
        }
    }
    return haspath_helper(input,n,solution,0,0);
}

int main(){
    int **arr;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<haspath(arr,n);
}