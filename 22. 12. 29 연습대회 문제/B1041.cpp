// 백준 1041 [그리디] 주사위!
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	vector<unsigned long long> vec(7);
	unsigned long long N, ans = 0, cnt = 0;

	cin >> N;
	for (int i = 1; i <= 6; i++) cin >> vec[i];

	// N이 1인 경우!
	if (N == 1) {
		int max = 0, sum = 0;
		for (int i = 1; i <= 6; i++) {
			if (max < vec[i]) max = vec[i];
			sum += vec[i];
		}

		cout << sum - max;
		return 0;
	}

	int a, b, c;
	a = min(vec[1], vec[6]);
	b = min(vec[2], vec[5]);
	c = min(vec[3], vec[4]);

	int case1 = min(min(a, b), c);
	int case2 = min(min(a + b, b + c), c + a);
	int case3 = a + b + c;

	// 3개의 면이 보이는 경우!
	ans += 4 * case3;
	cnt += 4 * 3;

	// 2개의 면이 보이는 경우!
	ans += ((N - 1) * 4 + (N - 2) * 4) * case2;
	cnt += ((N - 1) * 4 + (N - 2) * 4) * 2;

	// 1개의 면이 보이는 경우!
	unsigned long long num = ((N * N * 5) - cnt);
	ans += num * case1;

	cout << ans;
	return 0;
}