const int MAXN(1e5 + 5);

vector <pair<int, int>> Gr[MAXN];
vector <int> dist(MAXN, 2e9);

void dijkstra(int st)
{
	priority_queue <pair<int, int>> pq;
	for (pq.push({ dist[st] = 0, st }); pq.size();)
	{
		auto [cost, now](pq.top()); pq.pop();
		if (dist[now] < (cost *= -1)) continue;
		for (auto& [nxt, weight] : Gr[now])
		{
			int cur(cost + weight);
			if (cur < dist[nxt])
				pq.push({ -(dist[nxt] = cur), nxt });
		}
	}
}
