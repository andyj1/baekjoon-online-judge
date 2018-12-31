/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*   using permutations
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
  int N; //# of total players
  cin >> N;
  vector< vector<int> > S(N, vector<int> (N)); //2-D vector N x N
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> S[i][j];
    }
  }

  vector<int> prob (N); //assume initialized to 0
  for (int i = 0; i < N/2; i++){
    prob[i] = 1;
  }
  sort(prob.begin(), prob.end());
  int ans = INT_MAX/2; //prevent int overflow
  do {
    vector<int> first,second;
    for(int i = 0; i < N; i++){
      if(prob[i] == 0){
        first.push_back(i); //the team member # on either team
      } else {
        second.push_back(i);
      }
    }
    int val1 = 0, val2 = 0;
    for  (int i = 0; i < N/2; i++){
      for (int j = 0; j < N/2; j++){
        if (i == j) continue;
        val1 += S[first[i]][first[j]]; //add potentials
        val2 += S[second[i]][second[j]];
      }
    }

    int diff = val2 - val1;
    if (diff < 0) diff = -diff;
    if (ans > diff) ans = diff;
  }  while(next_permutation(prob.begin(), prob.end()));
  std::cout << ans << endl;
  return 0;
}
