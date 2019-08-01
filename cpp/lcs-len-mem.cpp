int lcs_len_mem(const string& s, const string& p) {
	int n = s.size(), m = p.size();
	vector<int> di(m+1, 0), dim1(m+1);
	for (int i=1; i<=n; i++) {
		swap(di, dim1);
		for (int j=1; j<=m; j++)
			if (s[i-1] != p[j-1])
				di[j] = max(dim1[j], di[j-1]);
			else
				di[j] = max({dim1[j], di[j-1], dim1[j-1]+1});
	}
	return di[m];
}
