#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/13537

vector <int> seg[1 << 18];
void update(int n, int s, int e, int i, int val)
{
	if (s > i || e < i) return;
	seg[n].push_back(val);
	if (s ^ e)
	{
		int m(s + e >> 1);
		update(n << 1, s, m, i, val);
		update(n << 1 | 1, m + 1, e, i, val);
	}
}
int query(int n, int s, int e, int l, int r, int k)
{
	if (s > r || e < l) return 0;
	if (s >= l && e <= r)
	{
		int idx(upper_bound(seg[n].begin(), seg[n].end(), k) - seg[n].begin());
		return seg[n].size() - idx;
	}
	int m(s + e >> 1);
	return query(n << 1, s, m, l, r, k) + query(n << 1 | 1, m + 1, e, l, r, k);
}
void segInit(int n)
{
	for (int i(1); i <= n; i++)
	{
		int val; cin >> val;
		update(1, 1, n, i, val);
	}
	for (int i{}; i < (1 << 18); i++)
		sort(seg[i].begin(), seg[i].end());
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	segInit(n);

	int q; cin >> q;
	while (q--)
	{
		int l, r, k; cin >> l >> r >> k;
		cout << query(1, 1, n, l, r, k) << '\n';
	}
}
