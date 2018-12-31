/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*   using backtracking
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//can only move 1 position, so alternate movement in x and y direction
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int go(vector<string> &board, vector<bool> &check, int x, int y) {
    int ans = 0;
    for (int k=0; k<4; k++) {
        //next x and y => nx, ny
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
            if (check[board[nx][ny]-'A'] == false) {
                //if the alphabet is seen, mark 'true'
                check[board[nx][ny]-'A'] = true;
                int next = go(board, check, nx, ny); //move to next position
                if (ans < next) {
                    ans = next;
                }
                //un-do
                check[board[nx][ny]-'A'] = false;
            }
        }
    }
    return ans + 1;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int alphabetSize = 26;
    vector<bool> check(alphabetSize);
    check[board[0][0]-'A'] = true;
    cout << go(board, check, 0, 0) << '\n';
    return 0;
}
