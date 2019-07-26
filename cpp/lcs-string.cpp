string lcs_string(const string& s, const string& p) {
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

	int i = n, j = m;
	string q;
	while (i > 0 && j > 0) {
		if (s[i-1] == p[j-1]) {
			if (d[i][j] == d[i-1][j-1] + 1)
				q += s[i-1], i--, j--;
			else if (d[i][j] == d[i-1][j])
				i--;
			else
				j--;
		} else {
			if (d[i][j] == d[i-1][j])
				i--;
			else
				j--;
		}
	}
	reverse(q.begin(), q.end());
	return q;
}