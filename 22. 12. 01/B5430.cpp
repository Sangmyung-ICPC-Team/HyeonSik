#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

	int n;
	cin >> n;

	for (int index = 0; index < n; index++) {
		string str, str_arr;
		int size, idx = 0;
		cin >> str;
		
		cin >> size;

		char num[4] = " ";
		vector<int> s;
		cin >> str_arr;

		for (int i = 0; i < str_arr.length(); i++) {
			char ch = str_arr[i];
			if (ch >= '0' && ch <= '9') num[idx++] = ch;
			
			if (ch == ',' && idx != 0) {
				s.push_back(atoi(num));
				for (int j = 0; j < idx; j++) num[j] = ' ';
				idx = 0;
			}
			
			if (ch == ']' && idx != 0) s.push_back(atoi(num));
		}

		bool reverse = false, error = false;
		int front = 0, back = 0;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'R') {
				if (reverse) reverse = false;
				else reverse = true;
			}

			if (str[i] == 'D') {
				if (front >= size || size <= back) {
					if (!reverse) front++;
					else back++;
					error = true;
				}

				else {
					if (!reverse) s[front++] = -1;
					else s[size - 1 - (back++)] = -1;
				}
			}
		}

		if (error) {
			cout << "error\n";
			continue;
		}

		if (!reverse) {
			cout << '[';
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != -1) {
					cout << s[i];
					if (i != s.size() - back - 1) cout << ',';
				}
			}
			cout << "]\n";
		}
		else {
			cout << '[';
			for (int i = s.size() - 1; i >= 0; i--) {
				if (s[i] != -1) {
					cout << s[i];
					if (i != front) cout << ',';
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}