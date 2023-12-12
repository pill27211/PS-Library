// LCAInit(root, 1)
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

/*
* N ≤ 100,000 -> j < 18
* N ≤ 200,000 -> j < 19
* N ≤ 500,000 -> j < 20
* .
* .
* .
*/
void TableDP()
{
	for (int j(1); j < 18; j++)
		for (int i(1); i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
