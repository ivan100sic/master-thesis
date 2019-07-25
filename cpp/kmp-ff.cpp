vector<int> kmp_ff(const string& p) {
	int m = p.size();
	vector<int> f(m+1);
	f[0] = -1;
	for (int i=1; i<=m; i++) {
		int r = f[i-1];
		while (r != -1 && p[r] != p[i-1])
			r = f[r];
		f[i] = r+1;
	}
	return f;
}
