/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int function(int M, int N, int x, int y){
  int max = 40000;
  for(int multM = 1; multM <= max/M; multM++){
    for(int multN = 1; multN <= max/N; multN++){
      int number = multM * M + x;
      if ((number % N) == y){
        return number;
      }
      if(number > (M*N)){
        return -1; //invalid
      }
    }
  }
}
int main(){
  int total;
  cin >> total;
  for(int i = 0; i < total; i++){
    int M, N, x, y;
    cin >> M >> N >> x >> y;
    int ans = function(M,N,x,y);
    cout << ans << endl;
    // printf("%d\n", ans);
  }
  return 0;
}
