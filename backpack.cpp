int weight();
int c[], m[], q[] = col;
int dp[weight][col + 1];
for (int i = 0; i < weight; i++)
	dp[i][0] = 0;
for (int i = 0; i < weight; i++) {
	for (int j = 1; j <= col; j++)
		if (m[j] <= i) {
			dp[i][j] = max(dp[i][j - 1], dp[i - m[j]][j - 1] + c[j]);
		}
		else dp[i][j] = dp[i][j - 1];
}
cout << dp[m - 1][col];

