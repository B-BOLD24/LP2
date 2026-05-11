#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **board, int currentRow, int currentColumn, int n){

    // Check same column
    for(int r = 0; r < currentRow; r++){
        if(board[r][currentColumn] == 1){
            return false;
        }
    }

    // Check upper-left diagonal
    int r = currentRow;
    int c = currentColumn;

    while(r >= 0 && c >= 0){
        if(board[r][c] == 1){
            return false;
        }
        r--;
        c--;
    }

    // Check upper-right diagonal
    r = currentRow;
    c = currentColumn;

    while(r >= 0 && c < n){
        if(board[r][c] == 1){
            return false;
        }
        r--;
        c++;
    }

    return true;
}

bool nQueens(int **board, int currentRow, int n){

    // Base condition
    if(currentRow >= n){
        return true;
    }

    // Try all columns
    for(int currentColumn = 0; currentColumn < n; currentColumn++){

        // Check if position is safe
        if(isSafe(board, currentRow, currentColumn, n)){

            // Place queen
            board[currentRow][currentColumn] = 1;

            // Recursive call for next row
            if(nQueens(board, currentRow + 1, n)){
                return true;
            }

            // Backtracking
            board[currentRow][currentColumn] = 0;
        }
    }

    return false;
}

int main(){

    int n;

    cout << "Enter value of N: ";
    cin >> n;

    // Create dynamic 2D array
    int **board = new int*[n];

    for(int i = 0; i < n; i++){

        board[i] = new int[n];

        for(int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }

    // Solve N-Queens problem
    if(nQueens(board, 0, n)){

        cout << "Solution:" << endl;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }
    else{
        cout << "Solution not possible";
    }

    return 0;
}
