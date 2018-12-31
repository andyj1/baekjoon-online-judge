/*  Jongoh (Andy) Jeong
*   Date: 12/2018
*   Reference: Baekjoon online judge
*
*/
#include <iostream>
#include <stdio.h>
int main(){
    int N;
    std::cin >> N;
    if(N <= 100000 && N > 0){
        for(int i = 1; i <= N; ++i){
            std::cout << i << endl;
        }
    }
    return 0;
}
