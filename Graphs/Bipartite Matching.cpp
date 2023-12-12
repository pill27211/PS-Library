const int MAXN(505);

vector <int> Visit(MAXN), assign(MAXN);
vector <int> Gr[MAXN];

int Match(int now)
{
	for (int& nxt : Gr[now])
		if (!Visit[nxt])
		{
			Visit[nxt] = 1;
			if (!assign[nxt] || Match(assign[nxt]))
				return assign[nxt] = now;
		}
	return 0;
}
