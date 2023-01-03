#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent;

typedef struct{
    int x1, x2, num;
}T;
vector<T> arr;

bool cmp (T &a, T &b){
    return a.x1 < b.x1;
}

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    
    int n, q;
    cin >> n >> q;
	
	parent.resize(n+1);
	arr.resize(n+1);

    int y;
    for (int i = 1; i <= n; i++) {
        parent[i] = i; // 부모 배열 초기화

        cin >> arr[i].x1 >> arr[i].x2 >> y; // y는 아무 상관 없다. 그냥 입력만 받아줌
        arr[i].num = i; // 몇번째 통나무인지, 순차저장
    } 
    sort(arr.begin()+1, arr.end(), cmp); // x1기준으로 오름차순 정렬

    int idx = 1, end = arr[1].x2;
    for (int i = 2; i <= n; i++) {
        // i번째 통나무가 범위 안에 있을 때
		if (arr[i].x1 <= end) {
            Union(arr[idx].num, arr[i].num);
			
			if (arr[i].x2 > end){
				idx = i;
				end = arr[i].x2;
			}
        }
        
		// i번째 통나무가 완전히 동떨어져 있을 때
		else {
			idx = i;
			end = arr[i].x2;
		}
    }

    for(int i=0; i<q; i++){
        int a, b; 
		cin >> a >> b;
        
		if (find(a) == find(b)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}
