void hldInit(int now)
{
	sz[now] = 1;
	for (int nxt : Gr[now])
	{
		if (sz[nxt]) continue;
		dep[nxt] = dep[now] + 1;
		par[nxt] = now;
		hldInit(nxt);
		sz[now] += sz[nxt];
		tree[now].push_back(nxt);

		if (sz[nxt] > sz[tree[now][0]]) swap(tree[now][0], tree[now].back());
	}
}
int cur;
void hldETT(int now)
{
	in[now] = ++cur;
	for (int nxt : tree[now])
	{
		top[nxt] = nxt ^ tree[now][0] ? nxt : top[now];
		hldETT(nxt);
	}
}
