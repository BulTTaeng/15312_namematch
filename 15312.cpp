#include <iostream>
#include <string>

using namespace std;

int dp[4002][4002];

int main() {
  int num[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
  string A , B;

  cin >> A ;
  cin >> B;

  int c = 0;

  for(int i =0; i<A.length()*2; i+=2){
    dp[0][i] = num[int(A[c]) - 65];
    dp[0][i+1] =  num[int(B[c]) - 65];
    c++;
  }

  for(int i =1; i<A.length()*2; i++){
    for(int j =0; j<A.length()*2-i; j++){
      dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]) % 10 ;
    }
  }

  int ans_loc = A.length()*2 - 2;

  cout << dp[ans_loc][0] << dp[ans_loc][1];
  return 0;

  
} 