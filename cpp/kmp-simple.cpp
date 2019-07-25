vector<int> kmp_simple(const string& s, const string& p) {
	string q = p + '\0' + s;
	int n = s.size(), m = p.size();
	vector<int> f(n+m+2), result;
	f[0] = -1;
	for (int i=1; i<=n+m+1; i++) {
		int r = f[i-1];
		while (r != -1 && q[r] != q[i-1])
			r = f[r];
		f[i] = ++r;
		if (r == m && i >= 2*m+1)
			result.push_back(i-2*m-1);
	}
	return result;
}