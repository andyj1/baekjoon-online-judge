#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

char alphabet[256];
int calcSum(vector<string> &strings, vector<char> &word, vector<int> &weight){
  int wordSize = word.size();
  int sum = 0;
  for (int i = 0; i < wordSize; i++){
    alphabet[word[i]] = weight[i];
    // std::cout << "word, weight: " << word[i] <<"\t" << weight[i]<< '\n';
  }
  for (string word : strings){
    int  now = 0;
    for (char wordChar : word){ //iterate from front to end, by character
      now = now * 10 + alphabet[wordChar]; // add weight corresponding to the letter(char)
    }
    sum += now;
  }
  return sum;
}

int main(){
  int n;
  cin >> n;
  vector<string> strings(n);
  vector<char> word;
  for (int i = 0; i < n; i++){
     cin >> strings[i]; //read in strings string and store each one in ith row of strings
     for (char x : strings[i]){ //for each char in each string
       word.push_back(x);
     }
  }
  sort(word.begin(), word.end());
  word.erase(unique(word.begin(), word.end()),  word.end());
  int wordSize = word.size();
  vector<int> weight;
  for (int i = 9; i > (9-wordSize); i--) {
    weight.push_back(i);
  }
  sort(weight.begin(), weight.end());
  int ans = 0;
  do{
    int now = calcSum(strings, word, weight);
    if(ans < now){
      ans = now;
    }
  } while(next_permutation(weight.begin(), weight.end()));
  // for (int i = 0; i < wordSize; i++){
  //   std::cout << "word, weight final: " << word[i] <<"\t" << weight[i]<< '\n';
  // }
  cout << ans << endl;
  return 0;
}
