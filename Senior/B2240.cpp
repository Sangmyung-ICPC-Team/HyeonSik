#include <iostream>
#include <vector>
using namespace std;

int dp[1001][31];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int T, W;
    cin >> T >> W;

    vector<int> apple(T + 1);

    for (int i = 1; i <= T; i++) cin >> apple[i];

    int ans = 0;
    for (int i = 1; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            // 1번 나무에 짝수번 이동
            // 2번 나무에 홀수번 이동
           if ( (apple[i] == 1 && !(j % 2)) || (apple[i] == 2 && (j % 2)) )
            dp[i][j] = (j == 0) ? dp[i-1][j] + 1 : max(dp[i-1][j-1], dp[i-1][j]) + 1;
           
           // 1번 나무에 홀수번 이동
           // 2번 나무에 짝수번 이동
           else
            dp[i][j] = (j == 0) ? dp[i-1][j] : max(dp[i-1][j-1], dp[i-1][j]);

            ans = ans < dp[i][j] ? dp[i][j] : ans; // 최댓값 구하기
        }
    }

    cout << ans;
    return 0;
}