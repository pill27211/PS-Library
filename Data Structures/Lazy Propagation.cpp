using ll = long long;

ll seg[1 << 18], lz[1 << 18]; // n ≤ 100,000
void propagation(ll n, ll s, ll e)
{
	if (!lz[n]) return;
	seg[n] += lz[n] * (e - s + 1);
	if (s ^ e)
	{
		lz[n << 1] += lz[n];
		lz[n << 1 | 1] += lz[n];
	}
}
ll update(ll n, ll s, ll e, ll l, ll r, ll val)
{
	propagation(n, s, e);
	if (s > r || e < l) return seg[n];
	if (s >= l && e <= r)
	{
		lz[n] = val;
		propagation(n, s, e);
		return seg[n];
	}
	ll m(s + e >> 1);
	return seg[n] = update(n << 1, s, m, l, r, val) + update(n << 1 | 1, m + 1, e, l, r, val);
}
ll query(ll n, ll s, ll e, ll l, ll r)
{
	propagation(n, s, e);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return seg[n];
	ll m(s + e >> 1);
	return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
}
