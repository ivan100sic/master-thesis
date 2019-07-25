vector<int> kmp_main(const string& s, const string& p) {
	vector<int> f = kmp_ff(p), result;
	int n = s.size(), m = p.size(), r = 0;
	for (int i=1; i<=n; i++) {
		while (r != -1 && p[r] != s[i-1])
			r = f[r];
		r++;
		if (r == m) {
			result.push_back(i-m);
			r = f[r];
		}
	}
	return result;
}