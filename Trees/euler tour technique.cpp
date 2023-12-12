int cur;
void ETT(int now)
{
	in[now] = ++cur;
	for (int nxt : Gr[now])
		ETT(nxt);
	out[now] = cur;
}
