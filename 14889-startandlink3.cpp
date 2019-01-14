/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*   using backtracking
*/
#include <iostream>
#include <vector>

using namespace std;
int s[20][20];
int n;
int go(int index, vector<int> &firstteam, vector<int> &secondteam){
  if(index == n){ //check if each team has n/2 members
    if (firstteam.size() != n/2) return -1; //diff = -1, or invalid
    if (secondteam.size() != n/2) return -1;
    int val1 = 0, val2 = 0;
    for (int i = 0; i < n/2; i++){
      for (int j = 0; j < n/2; j++){
        if (i == j) continue;
        val1 += s[firstteam[i]][firstteam[j]];
        val2 += s[secondteam[i]][secondteam[j]];
      }
    }
    int diff = val2-val1;
    if (diff < 0) diff=-diff;
    return diff;
  }
  // 차이점!
  //check if the size exceeded n/2
  if(firstteam.size() > n/2) return -1;
  if(secondteam.size() > n/2) return -1;

  int ans = -1;
  //insert members to team 1
  firstteam.push_back(index); //index from 0 to N-1 iteratively
  int val1 = go(index+1, firstteam, secondteam);
  if(ans == -1 || (val1 != -1 && ans > val1)){
    ans = val1;
  }
  // after finding the difference, the person in first
  // should no longer be in the first team, so pop_back()
  firstteam.pop_back();
  //due to recursion, needs to "un-do" push_back(before calling function)
  //after the function call
  //insert members to team 2
  secondteam.push_back(index); //index from 0 to N-1 iteratively
  int val2 = go(index+1, firstteam, secondteam);
  if(ans == -1 || (val2 != -1 && ans > val2)){
    ans = val2;
  }
  secondteam.pop_back();

  return ans;

}

int main() {
  cin >> n;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cin >> s[i][j];
    }
  }
  vector<int> firstteam, secondteam;
  int initialIndex = 0;
  cout << go(initialIndex, firstteam, secondteam) << '\n';
}
