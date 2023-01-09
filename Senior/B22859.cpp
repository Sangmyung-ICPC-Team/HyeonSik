// 백준 22859 [문자열] HTML 파싱...
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string str;

	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		if (str.substr(i, 11) == "<div title=") {
			cout << "title : ";
			i += 12;
			while (1) {
				cout << str[i++];

				if (str[i] == '"') break;
			}
			cout << '\n';
		}

		else if (str.substr(i, 3) == "<p>") {
			i += 3;

			string temp;
			while (1) {
				if (str.substr(i, 4) == "</p>") {
					i += 3;
					break;
				}

				// 1. 문장 내 태그 전부 제거!
				if (str[i] == '<') {
					while (str[i] != '>') i++;

					i++;
				}

				if (str.substr(i, 4) == "</p>") {
					i += 3;
					break;
				}

				// 2. 중복 공백 제거
				if ((temp.empty() || temp.back() != ' ' || str[i] != ' ') && str[i] != '<') temp.append(str.substr(i, 1));

				if (str[i] != '<') i++;
			}

			// 맨 뒤 공백 제거!
			while (temp.back() == ' ') temp.pop_back();

			// 맨 앞 공백 제거!
			while (temp.front() == ' ') temp.erase(0, 1);

			cout << temp << "\n";
		}
	}
}