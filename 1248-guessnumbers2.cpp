/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*   using backtracking
*/

#include <iostream>
#include <string>
using namespace std;

int n;
int sign[10][10];
int ans[10];
bool check(int index) {
    int sum = 0;
    for (int i=index; i>=0; i--) {
        sum += ans[i];
        if (sign[i][index] == 0) {
            if (sum != 0) return false;
        } else if (sign[i][index] < 0) {
            if (sum >= 0) return false;
        } else if (sign[i][index] > 0) {
            if (sum <= 0) return false;
        }
    }
    return true;
}
bool go(int index) {
    if (index == n) {
        return true;
    }
    // 컷팅 조건: 함수를 중간에 자를수 있는 조건 (contingency)
    // index번째 수를 결정하면, prev 수들(0 ~ index번째)은 변하지 않는다.
    // 따라서, 모든 sign[k][index](0 ≤ k <index)를 go(index)에서 검사할 수 있다
    if (sign[index][index] == 0) {
        ans[index] = 0;
        return check(index) && go(index+1);
    }
    for (int i=1; i<=10; i++) {
        ans[index] = sign[index][index]*i;
        if (check(index) && go(index+1)) 
            return true;
    }
    return false;
}
int main() {
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (s[cnt] == '0') {
                sign[i][j] = 0;
            } else if (s[cnt] == '+') {
                sign[i][j] = 1;
            } else {
                sign[i][j] = -1;
            }
            cnt += 1;
        }
    }
    go(0);
    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
