/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*   - prints out number of possible ways of N-queens arrangements
*     using backtracking, arrays (for shorter time complexity -> O(1))
*     ~ < O(N!)
*/

#include <iostream>
using namespace std;
bool a[15][15];
int n;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];
bool check(int row, int col) {
    // |
    if (check_col[col]) { //if queen is there, can't place
        return false;
    }
    // upper right diagonal
    if (check_dig[row+col]) {
        return false;
    }
    // upper left diagonal
    if (check_dig2[row-col+n]) {
        return false;
    }
    return true;
}
int calc(int row) {
    if (row == n) {
        // ans += 1;
        return 1;
    }
    int cnt = 0;
    for (int col=0; col <  n; col++) {
        if (check(row, col)) {
            //if there is no queen, can place there
            check_dig[row+col] = true;
            check_dig2[row-col+n] = true;
            check_col[col] = true;
            a[row][col] = true;

            cnt += calc(row+1);

            //after calling the recursive function, reset the conditions
            check_dig[row+col] = false;
            check_dig2[row-col+n] = false;
            check_col[col] = false;
            a[row][col] = false;
        }
    }
    return cnt;
}
int main() {
    cin >> n;
    cout << calc(0) << '\n';
    return 0;
}
