#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
vector<bool> visit;
queue<int> q;
vector<bool> cur;

int N, M;
bool drug = true;

// 마약이 공급이 되는지 안되는지
void bfs(int x) {
	// visit[x] = true;
	q.push(x);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		
		if (cur[front]) continue;

		for (int i = 0; i < v[front].size(); i++) {
			int r = v[front][i];
			if (!visit[r]) {
				q.push(r);
				visit[r] = true;
			}
		}
	}
}

// 그냥 방문을 했는지 안했는지
vector<bool> visit2;
void bfs2(int x) {
	visit2[x] = true;
	q.push(x);

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i = 0; i < v[front].size(); i++) {
			int r = v[front][i];
			if (!visit2[r]) {
				q.push(r);
				visit2[r] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	v.resize(N + 1);
	visit.resize(N + 1);
	visit2.resize(N + 1);
	cur.resize(26, false);

	for (int i = 0; i < M; i++) {
		char ch1, ch2;
		cin >> ch1 >> ch2;

		int num1, num2;
		num1 = ch1 - 'A';
		num2 = ch2 - 'A';

		v[num1].push_back(num2);
	}

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		char ch;
		cin >> ch;

		cur[ch - 'A'] = true;
	}

	// visit => 마약
	// visit2 => 방문
	for (int i = 0; i < N; i++) {
		if (!visit2[i]) {
			bfs(i);
			bfs2(i);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) if (visit[i] && !cur[i]) ans++;

	for (int i = 0; i < N; i++) if (visit[i]) cout << (char)(i + 'A') << ' ';

	cout << ans;
	return 0;
}