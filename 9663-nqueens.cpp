/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*   - prints out number of possible ways of N-queens arrangements
*     using recursions O(N^N)
*/
#include <iostream>
using namespace std;
bool board[15][15]; //max size 15x15
int N;
int ans = 0;

//checks for invalid positions
bool isSafe(int row, int col) {
    // column
    for (int i = 0; i < N; i++) {
        //row = existing queen's row; i = searching row
        if (i == row) continue;
        if (board[i][col]) {
            return false;
        }
    }
    // upper left diagonal
    // queen at (x,y)
    int x = row-1;
    int y = col-1;
    while (x >=0 && y >=0) {
        if (board[x][y] == true) { //if queen is at (x,y)
            return false;          //upper left diag (x-1,y-1) is invalid
        }
        x -= 1;
        y -= 1;
    }
    // upper right diagonal
    // queen at (x,y)
    x = row - 1;
    y = col + 1;
    while (x >= 0 && y < N) {
        if (board[x][y] == true) {
            return false;
        }
        x -= 1;
        y += 1;
    }
    return true;
}
void find(int row) {
    if (row == N) {
        ans += 1;
    }
    for (int col=0; col<N; col++) {
        board[row][col] = true;
        if (isSafe(row, col)) {
            find(row+1);
        }
        board[row][col] = false;
    }
}
int main() {
    cin >> N;
    find(0);
    cout << ans << '\n';
    return 0;
}
