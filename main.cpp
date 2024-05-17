#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 9;

bool isSafe(int board[N][N], int row, int col, int num) {
    // Check if 'num' is already in the same row
    for (int i = 0; i < N; i++)
        if (board[row][i] == num)
            return false;

    // Check if 'num' is already in the same column
    for (int i = 0; i < N; i++)
        if (board[i][col] == num)
            return false;

    // Check if 'num' is already in the same 3x3 box
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + boxRowStart][j + boxColStart] == num)
                return false;

    return true;
}

void printBoard(int grid[N][N]) {

    system("cls");
    cout << "\t\t\t<================================================================================>" << endl;
    cout << "\t\t\t|                        WELCOME TO SUDOKU Game!                                 |" << endl;
    cout << "\t\t\t|       Fill in the missing numbers(represented by 0) to solve the puzzle.       |" << endl;
    cout << "\t\t\t<================================================================================>" << endl;
    for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
}

bool solveSudoku(int board[N][N], int row, int col) {
    // If all cells are filled, the puzzle is solved
    if (row == N - 1 && col == N)
        return true;

    // Move to the next row if the current column is N
    if (col == N) {
        row++;
        col = 0;
    }

    // Skip the cells that already have a value
    if (board[row][col] != 0)
        return solveSudoku(board, row, col + 1);

    // Try filling the current cell with a number from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board, row, col + 1))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}

