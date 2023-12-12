const int MAXN(1e5 + 3);

vector <int> Gr[MAXN], in(MAXN);
bitset <MAXN> is_art;

int cur;
int getArtPoint(int now, int is_root)
{
	int _min(in[now] = ++cur), sz{};
	for (int nxt : Gr[now])
	{
		if (!in[nxt])
		{
			int cur(getArtPoint(nxt, 0));
			if (in[now] <= cur && !is_root)
				is_art[now] = 1;

			_min = min(_min, cur);
			sz++;
		}
		_min = min(_min, in[nxt]);
	}
	if (is_root && sz > 1)
		is_art[now] = 1;

	return _min;
}
