#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

	int num;
	cin >> num;

	vector<int> arr(num + 1), v(num + 1);
	stack<pair<int, int>> s;
	for (int i = 1; i <= num; i++) cin >> arr[i];

	for (int i = 1; i <= num; i++) {
		while (!s.empty() && s.top().first < arr[i]) s.pop();

		if (s.empty()) v[i] = 0;
		else v[i] = s.top().second;

		s.push({ arr[i],i });
	}
	
	for (int i = 1; i <= num; i++) cout << v[i] << ' ';
	
	return 0;
}