#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	int n;
	cin >> n;

  double ans = 0;
	
	vector<double> v(n + 1);
	
	for (int i = 1; i <= n; i++) cin >> v[i];
	
	for (double i = 1; i <= n; i++) {
		double left_min, right_max, cnt = 0;
		
		// 오른쪽 값
		for (double j = i + 1; j <= n; j++) {
      double n = (v[j] - v[i]) / (j - i); // 기울기
      
			if (j == i + 1){
        right_max = n;
        cnt++;
      }
      else {
        if (right_max < n) {
          right_max = n;
          cnt++;
        }
      }
		}
		
		// 왼쪽 값
		for (double j = i - 1; j > 0; j--) {
			double n = (v[j] - v[i]) / (j - i); // 기울기
      
			if (j == i - 1){
        left_min = n;
        cnt++;
      }
      else {
        if (left_min > n) {
          left_min = n;
          cnt++;
        }
      }
		}

    // cout << cnt << " " << i << "회차\n";
    ans = ans < cnt ? cnt : ans;
	}

  cout << ans;
  return 0;
}
