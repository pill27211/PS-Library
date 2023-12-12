const int MAXN(1e5 + 3);

vector <int> in(MAXN), out(MAXN);
vector <int> Gr[MAXN];

int cur;
void ETT(int now)
{
	in[now] = ++cur;
	for (int nxt : Gr[now])
		ETT(nxt);
	out[now] = cur;
}
