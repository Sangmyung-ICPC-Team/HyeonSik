// 백준 12852 [DP + 그래프탐색] 1로 만들고, 역추적하기!
#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

vector<int> dp, v;
vector<int> ans;
int num, cnt = 0;

void dfs(int node) {
	ans.push_back(node);
	if (node == 1) return;
	dfs(v[node]);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	cin >> num;
	
	v.resize(num + 1); 
	dp.resize(num + 1);
	
	dp[1] = 0, dp[2] = 1, dp[3] = 1;
	v[2] = v[3] = 1;

	for (int i = 4; i <= num; i++) {
		int Min = INF;
		int n;
		
		if (i % 3 == 0 && Min > dp[i / 3] + 1) {
			Min = dp[i / 3] + 1;
			n = i / 3;
			v[i] = i / 3;
		}
		if (i % 2 == 0 && Min > dp[i / 2] + 1) {
			Min = dp[i / 2] + 1;
			n = i / 2;
			v[i] = i / 2;
		}
		if (Min > dp[i - 1] + 1) {
			Min = dp[i - 1] + 1;
			n = i - 1;
			v[i] = i - 1;
		}

		dp[i] = Min;
		v.push_back(n);
	}

	dfs(num);

	cout << dp[num] << '\n';
	for (auto& e : ans) cout << e << ' ';

	return 0;
}