/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*
*/
#include <stdio.h>
#include <iostream>
using namespace std;

bool broken[10]; // 버튼이 고장나 있으면 true, else false
int possible(int c){
  if(c == 0){
    return broken[0] ? 0 : 1;
  }
  int len = 0;
  while( c > 0 ){
    if(broken[c % 10]) return 0;
    len += 1;
    c /= 10;
  }
  return len;
}

int main(){
  int n, m;
  // printf("enter initial number: ");
  cin >> n;
  // printf("enter number of broken buttons: ");
  cin >> m;
  for (int i = 0; i < m; i++){
    int x;
    // printf("enter broken numbers one by one: ");
    cin >> x;
    broken[x] = true;
  }
  int ans = (n-100); //initial channel is 100, so initialize to be at 0
  if (ans < 0){
    ans = -ans;
  }
  for (int i = 0; i <= 1000000; i++){
    int c = i;
    int len = possible(c); // if 0, not posible; not 0, possible
    if (len > 0){

        press = -press;
      }
      if(ans > len + press){
        //press =  # (only) +/- presses -> n
        //len = # (only) NUM presses -> c length
        //len + press = # NUM presses (-> c length) + # +/- presses (-> n)
        ans = len + press;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
