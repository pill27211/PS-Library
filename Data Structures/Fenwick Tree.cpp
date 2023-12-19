using ll = long long;

const int MAXN(1e5 + 1);

ll seg[MAXN];
void update(ll i, ll val)
{
	while (i < MAXN)
		seg[i] += val, i += i & -i;
}
ll query(ll i, ll res = 0)
{
	while (i)
		res += seg[i], i -= i & -i;
	return res;
}
