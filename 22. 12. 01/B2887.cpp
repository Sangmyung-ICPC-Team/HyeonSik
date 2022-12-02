// 백준 2887 [프림] 최소한의 간선들만 저장하는 최소신장트리
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;
typedef long long ll;

typedef struct pos {
    ll x;
    ll y;
    ll z;
    ll n;
}pos;

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq; // 최소힙

vector<bool> Find;
vector< vector<pair<int, ll>> > vec;
ll ans = 0;

void prim(int s) {
    Find[s] = true;

    for (auto& e : vec[s]) if (!Find[e.first]) pq.push({ e.second,e.first });

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();

        if (!Find[p.second]) {
            ans += p.first;
            prim(p.second);
            return;
        }
    }
}

ll min_cost(pos a, pos b) {
    vector<ll> arr(3);
    arr[0] = abs(a.x - b.x);
    arr[1] = abs(a.y - b.y);
    arr[2] = abs(a.z - b.z);

    ll ans = arr[0];

    for (int i = 0; i < 3; i++) if (ans > arr[i]) ans = arr[i];

    return ans;
}

int mode = 0;
bool cmp(pos a, pos b) {
    if (mode == 0) return a.x > b.x;
    else if (mode == 1) return a.y > b.y;
    else return a.z > b.z;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<pos> arr(N);
    vec.resize(N + 1);
    Find.resize(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
        arr[i].n = i + 1;
    }

    for (; mode < 3; mode++) {
        sort(arr.begin(), arr.end(), cmp);
        for (int i = 0; i < N - 1; i++) {
            ll cost = min_cost(arr[i], arr[i + 1]);
            vec[arr[i + 1].n].push_back({ arr[i].n,cost });
            vec[arr[i].n].push_back({ arr[i + 1].n,cost });
        }
    }

    prim(1);

    cout << ans;
    return 0;
}
