#include <stdio.h>

long long dp[31][61]={0,};

long long dfs (int w, int h) {
	if (w == 0) {
		return 1;
	}

	if (dp[w][h]) {
		return dp[w][h];
	}

	dp[w][h] = dfs(w-1, h+1);
	if (h > 0) {
		dp[w][h] += dfs(w, h-1);
	}
	return dp[w][h];
}

int main() {
	int N;

	scanf("%d", &N);
	while(N > 0 && N <= 30) {
		printf("%lld\n", dfs(N, 0));
	    scanf("%d", &N);
	}

	return 0;
}

// W와 H로 만들 수 있는 문자열 중 조건에 부합하는 경우의 수
// dp[w][h] = dp[w-1][h+1] + dp[w][h-1]

