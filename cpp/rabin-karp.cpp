vector<int> rabin_karp(
	const string& s, const string& p,
	int q, int M
) {
	int n = s.size(), m = p.size();
	int hp = prefixhash(p, q, M)[m], qm = modpow(q, m, M);
	vector<int> h = prefixhash(s, q, M), r;
	for (int i=0; i<=n-m; i++)
		if ((h[i+m] - h[i]*1ll*qm - hp) % M == 0)
			r.push_back(i);
	return r;
}
