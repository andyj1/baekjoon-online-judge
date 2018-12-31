#include <iostream>
#include <string>
using namespace std;
int n;
int sign[10][10];
int ans[10];
bool check() {
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += ans[j];
            if (sign[i][j] == 0 && sum != 0) {       // 0
                  return false;
            } else if (sign[i][j] > 0 && sum <= 0) { // +
                  return false;
            } else if (sign[i][j] < 0 && sum >= 0) { // -
                  return false;
            }
        }
    }
    return true;
}
bool go(int index) {
    if (index == n) {
        return check();
    }
    // since only -10~10 integers are known
    // iterate through all possible numbers
    for (int i=-10; i<=10; i++) {
        ans[index] = i;
        if (go(index+1)) return true;
    }
    return false;
}
int main() {
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (s[count] == '0') {
                sign[i][j] = 0;
            } else if (s[count] == '+') {
                sign[i][j] = 1;
            } else {
                sign[i][j] = -1;
            }
            count += 1;
        }
    }
    // sign[i][j] = -+0 -> -1,1,0
    go(0);
    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
