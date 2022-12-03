// 백준 10282 [다익스트라] 바이러스 감염되는 컴퓨터 개수
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 18549876543
typedef long long ll;

vector<ll> dist;
vector<vector<pair<int, ll>>> vec;

void dijkstra(int start) {
	dist[start] = 0; // 처음 위치는 0

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq; // 최대힙
	pq.push({ dist[start] , start });

	while (!pq.empty()) {
		int cur = pq.top().second; // 큐의 가장 맨 앞에 있는 정점의 번호를 담아온다.
		ll distance = pq.top().first;
		pq.pop();

		// 이미 담겨 있는 것보다 distance가 크면 넘어간다.
		if (dist[cur] < distance) continue;

		// 선택한 노드의 모든 인접 노드들을 확인한다.
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first; // 정점
			ll nextDistance = distance + vec[cur][i].second; // 비용

			// 다음 것과 기존의 비용과 비교
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push({ nextDistance , next });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int N, M, V;
		cin >> N >> M >> V;

		dist.resize(N + 1, INF);
		vec.resize(N + 1);

		for (int i = 1; i <= M; i++) {
			int a, dis;
			ll cur;
			cin >> a >> cur >> dis;
			vec[cur].push_back({ a,dis });
		}

		dijkstra(V);
		int cnt = 0, ans = -1;
		for (auto& e : dist) if (e != INF) cnt++;
		for (auto& e : dist) if (e != INF && ans < e) ans = e;

		cout << cnt << ' ' << ans << '\n';

		vec.clear();
		dist.clear();
	}

	return 0;
}