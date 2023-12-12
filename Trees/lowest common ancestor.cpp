const int MAXN(1e5 + 3);

vector <int> Gr[MAXN], dep(MAXN);
int dp[MAXN][18];

int LCAInit(int now, int depth)
{
	dep[now] = depth;
	for(int nxt : Gr[now])
		if (!dep[nxt])
		{
			dp[nxt][0] = now;
			LCAInit(nxt, depth + 1);
		}
}
void TableDP()
{
	for (int j(1); j < 18; j++)
		for (int i(1); i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
