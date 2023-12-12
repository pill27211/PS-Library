const int MAXN(1e5 + 3);

vector <int> Gr[MAXN];
bitset <MAXN> Visit;

void dfs(int now)
{
	Visit[now] = 1;
	for (int nxt : Gr[now])
		if (!Visit[nxt])
			dfs(nxt);
}
