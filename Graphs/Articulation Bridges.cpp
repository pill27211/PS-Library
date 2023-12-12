const int MAXN(1e5 + 3);

vector <pair<int, int>> art_eg;
vector <int> Gr[MAXN], in(MAXN);

int cur;
int getArtEdge(int now, int prev)
{
	int _min(in[now] = ++cur);
	for (int nxt : Gr[now])
	{
		if (nxt == prev) continue;
		if (!in[nxt])
		{
			int cur(getArtEdge(nxt, now));
			if (in[now] < cur)
				art_eg.emplace_back(now, nxt);
			_min = min(_min, cur);
		}
		_min = min(_min, in[nxt]);
	}
	return _min;
}
