/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*   using backtracking
*   optimized for solving this specific type of sudoku board data
*   to generalize solution, refer to "Knuth Algorithm X"
*/
#include <iostream>
using namespace std;
int board[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n=9;

int square(int x, int y) {
    return (x/3)*3+(y/3);
}

bool go(int z) {
    if (z == 81) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = z/n;
    int y = z%n; 
    if (board[x][y] != 0) {
        return go(z+1);
    } else {
        //insert i into (row x, col y)
        for (int i=1; i<=9; i++) {
            if (c[x][i] == false && c2[y][i] == false && c3[square(x,y)][i]== false) {
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                board[x][y] = i;
                if (go(z+1)) {
                    return true;
                }
                //un-do
                board[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
            }
        }
    }
    return false;
}
int main() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                c[i][board[i][j]] = true;
                c2[j][board[i][j]] = true;
                c3[square(i,j)][board[i][j]] = true;
            }
        }
    }
    go(0);
    return 0;
}
