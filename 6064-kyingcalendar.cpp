#include <iostream>
#include <stdio.h>
using namespace std;

int function(int N, int M, int x, int y){
  int max = 40000;
  for(int multN = 1; multN <= max/N; multN++){
    for(int multM = 1; multM <= max/M; multM++){
      int number = multN * N + x;
      // std::cout << "multN: " << multN << '\n';
      // std::cout << "number: " << number << '\n';
      if ((number % M) == y){
        return number;
      }
      else if(number > max){
        return -1; //invalid
      }
    }
  }
}
int main(){
  int total;
  cin >> total;
  for(int i = 0; i < total; i++){
    int ans;
    int N, M, x, y;
    cin >> N >> M >> x >> y;
    ans = function(N,M,x,y);
    // cout << ans << endl;
    printf("%d\n", ans); //faster than cout
  }
  return 0;
}
