#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int dis;
    int clipboard;
    int time;
}emoticon;

int S, ans;
// y축: 디스플레이의 이모티콘 수, x축: 클립보드의 이모티콘 수
// 예) visit[1][1] => 현재 화면에는 이모티콘 1개, 클립보드에는 1개
// 얘는 오로지 현재 상황을 보여주는거임
bool visit[1001][1001];

int BFS() {
    queue<emoticon> q;
    q.push({1, 0, 0}); // 디스플레이: 1, 클립보드: 0, 시간: 0초
    visit[1][0] = true;

    while(!q.empty()) {
        emoticon e = q.front();
        q.pop();

        if(e.dis == S) return e.time;

        if(0 < e.dis && e.dis <= 1000) {
            // 뭘 하든 시간은 1초씩 증가!
            e.time++;

            // 1. 클립보드에 복사 (덮어쓰기댐)
            if(!visit[e.dis][e.dis]) {
                visit[e.dis][e.dis] = true;
                // 두번째 인자가 클립보드, 화면에 있는 이모티콘 수 그대로 복사
                q.push({e.dis, e.dis, e.time});
            }

            // 2. 클립보드에서 화면으로 복사
            if (e.clipboard > 0 && e.dis + e.clipboard <= 1000) {
                if(!visit[e.dis + e.clipboard][e.clipboard]) {
                    visit[e.dis + e.clipboard][e.clipboard] = true;
                    // 첫번째 인자가 화면, 클립보드의 수만큼 화면에 추가
                    q.push({e.dis + e.clipboard, e.clipboard, e.time});
            }

            }

            // 3. 화면에서 이모티콘 한개 삭제
            if(!visit[e.dis - 1][e.clipboard]) {
                visit[e.dis - 1][e.clipboard] = true;
                // 화면에서 -1 해주면 댐
                q.push({e.dis - 1, e.clipboard, e.time});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> S;
    ans = BFS();
    cout << ans;

    return 0;
}
