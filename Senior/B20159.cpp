#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

	int n;
	cin >> n;

    vector<int> vec(n + 1, 0);

    vector<int> even_bsum(n/2 + 1, 0); // 짝수 bsum
    vector<int> odd_psum(n/2 + 1, 0);  // 홀수 psum

    for (int i = 1; i<= n; i++) cin >> vec[i];
	
    int b_idx = n;
    int p_idx = 1;
    for (int i = 1; i <= n/2; i++) {
        even_bsum[i] += even_bsum[i - 1] + vec[b_idx];
        odd_psum[i] += odd_psum[i - 1] + vec[p_idx];

        b_idx -= 2;
        p_idx += 2;
    }

    int ans = 0;
	for (int i = 1; i <= n/2; i++) {
        int a, b;

		a = odd_psum[i-1] + even_bsum[n/2 - (i - 1)];
        b = odd_psum[i] + even_bsum[n/2 - (i - 1)] - even_bsum[1];

        ans = max(ans, max(a, b));
	}

	cout << ans;
	return 0;
}