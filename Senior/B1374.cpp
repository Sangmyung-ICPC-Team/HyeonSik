#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq; // 종료시간 기준 오름차순
int n;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e, N;
        cin >> N >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end()); // 시작시간 오름차순 정렬

    pq.push(v[0].second);

	for (int i = 1; i < n; i++) {
        int next_start = v[i].first; // 다음 시작시간
        int pq_end = pq.top();       // 가장 먼저 종료하는 강의
		
        if (next_start >= pq_end) pq.pop();
		
        pq.push(v[i].second);
	}

	cout << pq.size();
	return 0;
}
