const int MAXN(1e5 + 3);

vector <int> Gr[MAXN];

void dfs(int now, int prev)
{
  	for (int nxt : Gr[now])
		if (nxt ^ prev)
			dfs(nxt, now);
}
