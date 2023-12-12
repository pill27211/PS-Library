void dfs(int now)
{
	Visit[now] = 1;
	for (int nxt : Gr[now])
		if (!Visit[nxt])
			dfs(nxt);
}
