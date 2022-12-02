// 백준 10844 [DP] 양옆의 숫자 차이가 1씩 난다.
#include <iostream>
#define mod 1000000000
using namespace std;

int main() {
	int num;
	cin >> num;

	int dp[101][10] = { 0, };

	for (int i = 1; i < 10; i++) dp[1][i] = 1;

	for (int i = 2; i <= num; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][1] % mod;
			else if (j == 9) dp[i][j] = dp[i - 1][8] % mod;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) sum = (sum + dp[num][i]) % mod;

	cout << sum << '\n';
	return 0;
}