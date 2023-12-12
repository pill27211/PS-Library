const int MAXN(505);

vector <int> Visit(MAXN), assign(MAXN);
vector <int> Gr[MAXN];

int f(int now)
{
	for (int& nxt : Gr[now])
		if (!Visit[nxt])
		{
			Visit[nxt] = 1;
			if (!assign[nxt] || f(assign[nxt]))
				return assign[nxt] = now;
		}
	return 0;
}
