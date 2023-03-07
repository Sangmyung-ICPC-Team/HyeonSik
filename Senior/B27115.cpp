// 백준 27115 [BFS] 통신소
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int R, C, K;
int board[3000][3000];
vector<pair<int, pair<int, int>>> vec;
queue<pair<int, int>> que;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

int ans;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C >> K;

	vec.resize(K);

	for (int i = 0; i < K; i++){
		int r, c, w; 
		cin >> r >> c >> w;
		vec[i] = {w, {r - 1, c - 1}};
	}

	sort(vec.begin(), vec.end());

	for (int w = 3000; w > 0; w--) {
		while (!vec.empty() && vec.back().first == w) {
			int y = vec.back().second.first;
			int x = vec.back().second.second;
			
			if (!board[y][x]) {
				board[y][x] = 1;
				que.push({y, x});
			}

			vec.pop_back();
		}
		
		int qsize = que.size();
		while (qsize--) {
			int r = que.front().first;
			int c = que.front().second; 
			que.pop();

			for (int i = 0; i < 4; i++) {
				int rr = r + dr[i];
				int cc = c + dc[i];
				
				if (rr < 0 || rr >= R || cc < 0 || cc >= C || board[rr][cc]) continue;
				
				board[rr][cc] = 1;
				que.push({rr, cc});
			}
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			ans += board[r][c];
		}
	}

	cout << ans;
}