vector<vector<int>> lcp_matrix(const string& s) {
	int n = s.size();
	vector<vector<int>> a(n, vector<int>(n));
	for (int i=n-1; i>=0; i--)
		for (int j=n-1; j>=0; j--)
			if (s[i] != s[j])
				a[i][j] = 0;
			else if (i != n-1 && j != n-1)
				a[i][j] = a[i+1][j+1] + 1;
			else
				a[i][j] = 1;
	return a;
}
