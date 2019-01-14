/*  Jongoh (Andy) Jeong
*   Date: 1/2019
*   Reference: Baekjoon online judge
*   using bitmask
*/

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int LIMITmoves = 5;

vector<int> gen (int k) {
    vector<int> dir (LIMITmoves);
    for (int i=0; i < LIMITmoves; i++) {
        dir[i] = (k & 3); // equal to (% 4) remainder
        k >>= 2;        // equal to (/ 4) quotient
    }
    return dir;
}
void print(vector<vector<pair<int,bool>>> &a) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j].first << ' ';
        }
        cout << '\n';
    }
}
int check(vector<vector<int>> &a, vector<int> &dirs) {
    int n = a.size();
    vector<vector<pair<int,bool>>> d(n, vector<pair<int,bool>>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            d[i][j].first = a[i][j];
        }
    }
    // 0: down, 1: up, 2: left, 3: right
    for (int dir : dirs) {
        //initialization
        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j].second = false;
            }
        }

        while (true) {
            ok = false;
            if (dir == 0) { // down
                for (int i = n-2; i >= 0; i--) {
                    for (int j=0; j<n; j++) {
                        if (d[i][j].first == 0) 
                            continue;
                        if (d[i+1][j].first == 0) {
                            d[i+1][j].first = d[i][j].first;
                            d[i+1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i+1][j].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i+1][j].second == false) {
                                d[i+1][j].first *= 2;
                                d[i+1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 1) { // up
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i-1][j].first == 0) {
                            d[i-1][j].first = d[i][j].first;
                            d[i-1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i-1][j].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i-1][j].second == false) {
                                d[i-1][j].first *= 2;
                                d[i-1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 2) {  // left
                for (int j = 1; j < n; j++) {
                    for (int i = 0; i < n; i++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j-1].first == 0) {
                            d[i][j-1].first = d[i][j].first;
                            d[i][j-1].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i][j-1].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i][j-1].second == false) {
                                d[i][j-1].first *= 2;
                                d[i][j-1].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 3) { // right
                for (int j = n-2; j >= 0; j--) {
                    for (int i = 0; i < n; i++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j+1].first == 0) {
                            d[i][j+1].first = d[i][j].first;
                            d[i][j+1].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i][j+1].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i][j+1].second == false) {
                                d[i][j+1].first *= 2;
                                d[i][j+1].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } // end if loop
            if (ok == false) // no movement made
                break;
        } // end while loop
    } // end for loop
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (ans < d[i][j].first) {
                ans = d[i][j].first;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    for (int k = 0; k < (1<<(LIMITmoves*2)); k++) {
        vector<int> dir = gen(k);
        int cur = check(board, dir);
        if (ans < cur) 
            ans = cur;
    }
    cout << ans << '\n';
    return 0;
}