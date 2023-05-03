from sys import stdin as s
import sys

print = sys.stdout.write

n = int(s.readline()) # n입력

wine = [0] * (n + 1)
dp = [0] * (n + 1)

for i in range(1,n + 1):
    wine[i] = int(s.readline()) # 포도주(와인) 양 입력

dp[1] = wine[1] # 첫번째 dp 설정
ans = dp[1] # 최댓값

if(n >= 2): # 1 <= n <= 10,000
    dp[2] = wine[1] + wine[2]
    ans = max(ans, dp[2])

for i in range(3, n+1):
    dp[i] = max(ans, max(dp[i-3]+wine[i-1], dp[i-2]) + wine[i]) # 점화식!
    ans = max(ans, dp[i]) # 최댓값 설정

print("%d" % ans)