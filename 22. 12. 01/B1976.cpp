#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
vector<bool> visit;
vector<int> vec;
queue<int> q;

void bfs(int x) {
	int cnt = 1;
	visit[x] = true;
	q.push(x);

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i = 0; i < v[front].size(); i++) {
			int r = v[front][i];
			if (!visit[r]) {
				q.push(r);
				visit[r] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	v.resize(N + 1);
	visit.resize(N + 1, false);
	vec.resize(M);

	int n;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> n;
			if (n == 1) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < M; i++) cin >> vec[i];
	
	bfs(vec[0]);

	bool ans = true;

	for (auto& e : vec) if (!visit[e]) ans = false;

	if (ans) cout << "YES";
	else cout << "NO";

	return 0;
}