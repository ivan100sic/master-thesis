vector<int> prefixhash(const string& s, int q, int m) {
	int n = s.size();
	vector<int> h(n+1);
	h[0] = 0;
	for (int i=1; i<=n; i++)
		h[i] = (h[i-1] * 1ll * q + s[i-1]) % m;
	return h;
}
