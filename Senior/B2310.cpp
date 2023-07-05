#include <iostream>
#include <vector>
using namespace std;

int N = 1;
vector<pair<char, int>> Type;
vector<vector<int>> DoorNum;
vector<bool> visit;

void dfs(int num, int money) {
    visit[num] = true;

    // 레프리콘 있는 방에 들감
    if(Type[num].first == 'L')
        if(money < Type[num].second) money = Type[num].second;
    
    // 개트롤 있는 방에 들감
    if(Type[num].first == 'T') {
        money -= Type[num].second;

        if(money < 0) {
            visit[num] = false;
            return;
        }
    }

    // N번방 까지 갔으면 끝!
    if (num == N) return;

    // 이제 다음 방 찾아서 들가야지~
    for (int i = 0; i < DoorNum[num].size(); i++) {
        int next = DoorNum[num][i];
        if (visit[next]) continue;

        dfs(next, money);
    }

    // visit[num] = false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    while(1) {
        cin >> N;
        if (!N) break;

        DoorNum.resize(N + 1);
        Type.resize(N + 1);
        visit.resize(N + 1, false);

        for (int i = 1; i <= N; i++) {
            cin >> Type[i].first >> Type[i].second;

            int n;
            while(1) {
                cin >> n;
                if (!n) break;

                DoorNum[i].push_back(n);
            }
        }

        dfs(1, 0);

        for (int i = 1; i <= N; i++) {
            if(!visit[i]) {
                cout << "No\n";
                break;
            }

            if (i == N) cout << "Yes\n";
        }
    }

    return 0;
}