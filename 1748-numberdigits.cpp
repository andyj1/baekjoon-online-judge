/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*
*/
#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int N;
  cin >> N; //number

  int len = 0, digit = 0;
  int temp = N;
  while(temp > 0){
    temp /= 10;
    len +=1;
  }
  // cout << "length: " << len << endl;
  // N = 120
  // 1~9 length 1
  // 10~99 length 2
  // 100~120 length 3
  for(int i = 1; i <= len;i++){
    int countDiff;
    // cout << "pow(10,i): " << pow(10,i) << endl;
    if( N >= pow(10,i) ){
      digit += ( (pow(10,i)-1) - (pow(10,i)/10) + 1) * i;
      // cout << "digit added: " << ( (pow(10,i)-1) - (pow(10,i)/10) + 1) * i << endl;
    }
    if(N < pow(10,i)){
      countDiff = (N - pow(10,i-1) + 1);
      digit += countDiff * i;
      // cout << "digit added: " << countDiff * i << endl;
    }
  }
  cout << digit << endl;
}
