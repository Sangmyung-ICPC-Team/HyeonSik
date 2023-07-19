#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;
vector<vector<int>> party;
vector<int> trust;

// 루트 노드 찾기
int find(int x) {
	if (x == parent[x]) return x; // 같으면 루트노드

	parent[x] = find(parent[x]); // 재귀로 부모노드 접근
	return parent[x];
}

// 합치기
void Union(int x, int y) {
	// 각 부모노드를 비교
	x = find(x);
	y = find(y);

	if (x == y) return; // 이미 같은 집합
	else parent[y] = x; // 합한다
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	parent.resize(n + 1);
	party.resize(m);

	int N;
	cin >> N;
	trust.resize(N);
	for (int i = 0; i < N; i++) cin >> trust[i];

	// 초기화
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		party[i].resize(num);

		for (int j = 0; j < num; j++) cin >> party[i][j];
	}

	if (!N) {
		cout << m;
		return 0;
	}

	// 사람의 수: N 파티의 수: M
	for (int i = 0; i < m; i++) {
		int k = party[i][0];

		for (int j = 1; j < party[i].size(); j++) Union(k, party[i][j]);
	}

	int ans = 0;
	// 사람의 수: N 파티의 수: M
	for (int i = 0; i < m; i++) {
		// party[i].size(): 파티에 오는 사람 수
		for (int j = 0; j < party[i].size(); j++) {
			bool flag = true;
			for (int k = 0; k < N; k++) {
				if (find(party[i][j]) == find(trust[k])) {
					flag = false;
					ans++;
					break;
				}
			}

			if (!flag) break;
		}
	}

	cout << m - ans;
	return 0;
}
