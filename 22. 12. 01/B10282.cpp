// ���� 10282 [���ͽ�Ʈ��] ���̷��� �����Ǵ� ��ǻ�� ����
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 18549876543
typedef long long ll;

vector<ll> dist;
vector<vector<pair<int, ll>>> vec;

void dijkstra(int start) {
	dist[start] = 0; // ó�� ��ġ�� 0

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq; // �ִ���
	pq.push({ dist[start] , start });

	while (!pq.empty()) {
		int cur = pq.top().second; // ť�� ���� �� �տ� �ִ� ������ ��ȣ�� ��ƿ´�.
		ll distance = pq.top().first;
		pq.pop();

		// �̹� ��� �ִ� �ͺ��� distance�� ũ�� �Ѿ��.
		if (dist[cur] < distance) continue;

		// ������ ����� ��� ���� ������ Ȯ���Ѵ�.
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first; // ����
			ll nextDistance = distance + vec[cur][i].second; // ���

			// ���� �Ͱ� ������ ���� ��
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