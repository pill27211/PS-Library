void dfs(int now, int prev)
{
  for (int nxt : Gr[now])
		if (nxt ^ prev)
			dfs(nxt, now);
}
