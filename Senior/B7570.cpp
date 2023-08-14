#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int N, x, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> x;
		dp[x] = dp[x - 1] + 1;

		ans = max(ans, dp[x]);
	}

	cout << N - ans;
	return 0;
}
