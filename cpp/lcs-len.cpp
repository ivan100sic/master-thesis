int lcs_len(const string& s, const string& p) {
	int n = s.size(), m = p.size();
	vector<vector<int>> d(n+1, vector<int>(m+1));
	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
			if (i == 0 || j == 0)
				d[i][j] = 0;
			else if (s[i-1] != p[j-1])
				d[i][j] = max(d[i-1][j], d[i][j-1]);
			else
				d[i][j] = max({d[i-1][j], d[i][j-1], d[i-1][j-1]+1});
	return d[n][m];
}
