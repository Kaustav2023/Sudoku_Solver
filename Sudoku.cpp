#include<bits/stdc++.h>
using namespace std;

bool isValid(int row,int col,vector<vector<char>>&board,char c){

    for(int i=0;i<9;i++){
        if(board[i][col]==c){
            return false;
        }
        if(board[row][i]==c){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){
            return false;
        }
    }
    return true;
}



bool Sudoku(vector<vector<char>>&board){

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){

            if(board[i][j]=='.'){
                
                for(char c='1';c<='9';c++){

                    if(isValid(i,j,board,c)){
                       board[i][j]=c;
                    
                       if(Sudoku(board)) return true;
                       else
                       board[i][j]='.';
                }
               
            }
             return false;
        }
      }
    }
    return true;
}


int main(){

    vector<vector<char>>sudo{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    cout<<"Sudoku problem "<<endl;
    cout<<"-------------------------------------------------"<<endl;
    for(int i=0;i<sudo.size();i++){
        for(int j=0;j<sudo.size();j++){
            cout<<sudo[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------------------------------------------------"<<endl;
    cout<<"After Solving the Sudoku Puzzle "<<endl;
    Sudoku(sudo);
    for(int i=0;i<sudo.size();i++){
        for(int j=0;j<sudo.size();j++){
            cout<<sudo[i][j]<<" ";
        }
        cout<<endl;
    }
}