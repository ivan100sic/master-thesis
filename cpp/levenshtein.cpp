int levenshtein(const string& s, const string& p) {
	int n = s.size(), m = p.size();
	vector<vector<int>> d(n+1, vector<int>(m+1));
	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
			if (i == 0 || j == 0)
				d[i][j] = i+j;
			else
				d[i][j] = min({d[i-1][j]+1, d[i][j-1]+1,
					d[i-1][j-1] + (s[i-1] != p[j-1])});
	return d[n][m];
}
