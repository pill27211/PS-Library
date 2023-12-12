const int MAXN(505);

int dp[MAXN][MAXN];

void Floyd()
{
	memset(dp, 0x3f3f3f3f, sizeof dp);
	for (int i(1); i <= n; i++)
		dp[i][i] = 0;

	for (int k(1); k <= n; k++)
		for (int i(1); i <= n; i++)
			for (int j(1); j <= n; j++)
				if (dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];
}
