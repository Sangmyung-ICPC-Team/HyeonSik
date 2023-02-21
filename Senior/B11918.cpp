// 백준 11918 [스위핑 + 그리디] 정전
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> vec(N);

    for (int i = 0; i < N; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    int s = vec[0] - L, e = vec[0] + L;
    long long ans = 0;
    for (int i = 1; i < N; i++) {
        int next_s = vec[i] - L, next_e = vec[i] + L;
        
        if(e > next_s) {
            if (next_s < s) next_s = s;
            
            ans += e - next_s;
            s = e;
            e = next_e;
        }
        else {
            s = next_s;
            e = next_e;
        }
    }

    cout << ans;
    return 0;
}