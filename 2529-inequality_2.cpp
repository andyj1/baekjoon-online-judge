//using backtracking strategy
// reference: baekjoon online judge

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
char inequality[20];
vector<string> ans;
bool check[10];
bool good(char x, char y, char op) {
    if (op == '<') {
        if (x > y) return false;
    }
    if (op == '>') {
        if (x < y) return false;
    }
    return true;
}
void go(int index, string num) {
    if (index == n+1) {
        ans.push_back(num);
        return;
    }
    for (int i=0; i<=9; i++) {
        if (check[i]) continue;
        if (index == 0 || good(num[index-1], i+'0', inequality[index-1])) {
            check[i] = true;
            go(index+1, num + to_string(i));
            check[i] = false;
        }
    }
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> inequality[i];
    }
    go(0, "");
    //sort in increasing order
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << '\n';
    cout << *p.first << '\n';
    return 0;
}
