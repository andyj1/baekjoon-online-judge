/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*   using bitmask - 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s[20][20];
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> s[i][j];
        }
    }
    int ans = -1;
    for (int i=0; i < (1 << n); i++) {
        vector<int> first, second;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                first.push_back(j); //0 이면 first 팀
            } else {
                second.push_back(j); //1 이면 second 팀
            }
        }
        // 컷팅 조건
        if (first.size() != n/2) continue;
        int t1 = 0;
        int t2 = 0;
        for (int idx=0; idx < n/2; idx++) {
            for (int idx2=0; idx2 < n/2; idx2++) {
                if (idx == idx2) continue;
                t1 += s[first[idx]][first[idx2]];
                t2 += s[second[idx]][second[idx2]];
            }
        }
        int diff = t1-t2;
        if (diff < 0) diff = -diff;
        if (ans == -1 || ans > diff) {
            ans = diff;
        }
    }
    cout << ans << '\n';
} 