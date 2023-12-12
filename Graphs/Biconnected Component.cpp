#include<bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
const int MAXN(1e5 + 3);

vector <int> Gr[MAXN], in(MAXN);
vector <vector<pi>> BCC;

stack <pi> st; int cur;
int getBCC(int now, int prev)
{
	int _min(in[now] = ++cur);
	for (int nxt : Gr[now])
	{
		if (nxt == prev) continue;
		if (in[now] > in[nxt]) st.push({ now, nxt });
		if (!in[nxt])
		{
			int cur(getBCC(nxt, now));
			_min = min(_min, cur);

			if (in[now] > cur) continue;

			vector <pi> V;
			while (1)
			{
				pi top(st.top()); st.pop();
				V.emplace_back(top);
				if (top == pi(now, nxt)) break;
			}
			BCC.emplace_back(V);
		}
		_min = min(_min, in[nxt]);
	}
	return _min;
}
