#include<iostream>
#include<vector>
using namespace std;

int combination(int amount, vector<int>& coins,int i){
    if(amount<0 || i>=coins.size()){
        return 0;
    }
    if(amount==0){
        return 1;
    }
    int acc=combination(amount-coins[i],coins,i);
    int notAcc=combination(amount,coins,i+1);
    return acc+notAcc;
}
int dpCombination(int amount, vector<int>& coins){
    int **output=new int*[amount+1];
    int n=coins.size();
    for(int i=0;i<=amount;i++){
        output[i]=new int[coins.size()+1];
    }
    for(int i=0;i<=amount;i++){
        output[i][0]=0;
    }
    for(int i=0;i<=coins.size();i++){
        output[0][i]=1;
    }
    
    for(int i=1;i<=amount;i++){
        for(int j=1;j<=coins.size();j++){
            if(j-coins[i-1]<0){
                output[i][j]=output[i-1][j];
            }
            else
            output[i][j]=output[i-1][j]+output[i][j-coins[i-1]];
        }
    }
    return output[amount][coins.size()];


}
int main(){
    vector<int> coin;
    coin.push_back(1);
    coin.push_back(2);
    coin.push_back(5);
    cout<<combination(5,coin,0);
    cout<<dpCombination(5,coin);

    return 0;
}