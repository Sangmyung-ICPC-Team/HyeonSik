#include <iostream>
#include <queue>
#include <vector>
#define ll pair<int,int>
using namespace std;

int N, S, E;
vector<vector<pair<int,int>>> v;
queue<pair<ll, int>> q;
int ans = 0;

void BFS() {
	bool visit[100001]{};
	visit[S] = true;
	q.push({{S,0},0});

	while (!q.empty()) {
		int n = q.front().first.first;
    int cost = q.front().first.second;
    int Max = q.front().second;
		q.pop();

		for (int i = 0; i < v[n].size(); i++) {
			int next = v[n][i].first;
      int next_cost = v[n][i].second + cost;

      if (next == E) {
        Max = max(Max, v[n][i].second);
        ans = next_cost - Max;
        return;
      }
      
			else if (!visit[next]) {
        Max = max(Max, v[n][i].second);
				q.push({{next, next_cost}, Max});
				visit[n] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

  cin >> N >> S >> E;

  v.resize(N + 1);

  for (int i = 1; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }

  BFS();

  cout << ans;
  return 0;
}
