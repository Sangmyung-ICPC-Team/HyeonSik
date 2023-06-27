#include <iostream>
#include <vector>
#define hash 1000000007
#define ll long long
using namespace std;

ll dp[100001][4];
/*
dp[i][1]: -0.5단계 사용했을 경우
dp[i][2]: 내껏만 이기적으로 사용한 경우!
dp[i][3]: +0.5단계 사용했을 경우
*/

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<ll> difficulty(n + 1, 0); // 난이도가 i인 문제 개수
    vector<ll> Diff2(n + 1, 0);      // 난이도가 i or i + 1인 문제 개수

    for (int i = 1; i <= n; i++) cin >> difficulty[i];

    for (int i = 1; i < n; i++) cin >> Diff2[i];

    dp[1][1] = 0, dp[1][2] = difficulty[1], dp[1][3] = Diff2[1];

    for (int i = 2; i <= n; i++) {
        dp[i][1] = ( (dp[i-1][1] + dp[i-1][2]) * Diff2[i - 1] + dp[i-1][3] * (Diff2[i - 1] - 1) ) % hash; // -0.5
        dp[i][2] = ( (dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) * difficulty[i] ) % hash;                     // 내꺼
        dp[i][3] = ( (dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) * Diff2[i] ) % hash;                          // +0.5
    }

    cout << (dp[n][1] + dp[n][2] + dp[n][3]) % hash;
    return 0;
}