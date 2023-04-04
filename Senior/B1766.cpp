// 백준 1766 [위상정렬] 문제집
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[32001];
vector<int> cnt;
priority_queue<int, vector<int>, greater<int> > q; // 오름차순 우선순위 큐

void TopologicalSort_DFS() {
	while (!q.empty()) {
		int t = q.top();
		q.pop();

		cout << t << ' ';

		for (int i = 0; i < v[t].size(); i++) {
			int Num = v[t][i]; // 탐색할 문제 번호
			cnt[Num]--; // 들어오는 간선 갯수

			if (cnt[Num] == 0) q.push(Num);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	cnt.resize(N + 1);
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		cnt[b]++;
	}

	for (int i = 1; i <= N; i++) if (cnt[i] == 0) q.push(i);

	TopologicalSort_DFS();

	return 0;
}
