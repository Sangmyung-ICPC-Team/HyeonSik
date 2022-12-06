#include <iostream>
#include <vector>
using namespace std;

int dp[3][200001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N = 0;
	cin >> N;

	for (int index = 0; index < N; index++) {
		int n;
		cin >> n;
		int dp[3][100001];
		vector<vector<int>> v(2);

		for (int idx = 0; idx < 2; idx++) {
			for (int i = 0; i < n; i++) {
				int num;
				cin >> num;
				v[idx].push_back(num);
			}
		}

		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		dp[2][0] = 0;

		int ans = 0;
		for (int i = 1; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + v[0][i];

			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + v[1][i];

			dp[2][i] = max(dp[2][i - 1], max(dp[1][i - 1], dp[0][i - 1]));
		}

		for (int j = 0; j < 3; j++) {
			int a = dp[j][n - 1];
			if (ans < a) ans = a;
		}

		cout << ans << '\n';
	}

	return 0;
}