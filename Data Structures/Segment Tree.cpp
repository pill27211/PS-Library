using ll = long long;

ll seg[1 << 18]; // n ≤ 100,000
ll update(ll n, ll s, ll e, ll i, ll val)
{
	if (s > i || e < i) return seg[n];
	if (s == e) return seg[n] = val;
	ll m(s + e >> 1);
	return seg[n] = update(n << 1, s, m, i, val) + update(n << 1 | 1, m + 1, e, i, val);
}
ll query(ll n, ll s, ll e, ll l, ll r)
{
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return seg[n];
	ll m(s + e >> 1);
	return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
}
