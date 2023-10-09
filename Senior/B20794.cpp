#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;
int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vec.resize(N + 1);

	int ans = 0;

	// first : 무게 second : value
	for (int i = 1; i <= N; i++) {
		cin >> vec[i].first >> vec[i].second;
		ans += vec[i].second;
	}

	for (int i = 1; i <= N; i++) {
		int weight = vec[i].first;
		int value = vec[i].second;

		for (int j = 1; j <= K; j++)
			dp[i][j] = (j >= weight) ? max(dp[i - 1][j], dp[i - 1][j - weight] + value) : dp[i - 1][j];
	}

	cout << ans - dp[N][K];
	return 0;
}
