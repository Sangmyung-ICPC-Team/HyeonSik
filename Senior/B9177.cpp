#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

	int num;
	cin >> num;

	for (int idx = 1; idx <= num; idx++) {
		string a, b, c;
		cin >> a >> b >> c;

		int a_size = a.length();
		int b_size = b.length();
		int c_size = c.length();

		int dp[205][205];

		dp[0][0] = 1;

		for (int i = 1; i <= a_size; i++) {
			if (a[i - 1] == c[i - 1]) dp[0][i] = dp[0][i-1];
			else dp[0][i] = 0;
		}

		for (int i = 1; i <= b_size; i++) {
			if (b[i - 1] == c[i - 1]) dp[i][0] = dp[i-1][0];
			else dp[i][0] = 0;
		}

		for (int i = 1; i <= b_size; i++) {
			for (int j = 1; j <= a_size; j++) {
				int c_idx = i + j - 1;
				char c_ch = c[c_idx];

				if (c_ch != a[j-1] && c_ch != b[i-1]) dp[i][j] = 0;

				else if (c_ch == a[j - 1] && c_ch == b[i - 1]) dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

				else if (c_ch == a[j-1]) dp[i][j] = dp[i][j - 1];

				else if (c_ch == b[i-1]) dp[i][j] = dp[i - 1][j];
			}
		}

		cout << "Data set " << idx << ": ";
		if (dp[b_size][a_size] == 1) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}