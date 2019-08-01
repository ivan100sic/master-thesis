string lpalsubseq(const string& s) {
	int n = s.size();
	vector<vector<int>> d(n, vector<int>(n+1));
	for (int l=n-1; l>=0; l--) {
		d[l][l+1] = 1;
		if (l+2 <= n)
			d[l][l+2] = 1 + (s[l] == s[l+1]);
		for (int r=l+3; r<=n; r++) {
			d[l][r] = max(d[l+1][r], d[l][r-1]);
			if (s[l] == s[r-1])
				d[l][r] = max(d[l][r], d[l+1][r-1]+2);
		}
	}
	int l = 0, r = n;
	string prefix, middle;
	while (r-l > 2) {
		if (s[l] == s[r-1] && d[l+1][r-1]+2 == d[l][r])
			prefix += s[l], l++, r--;
		else if (d[l+1][r] == d[l][r])
			l++;
		else
			r--;
	}
	if (r-l == 2 && s[l] == s[l+1])
		middle = s.substr(l, 2);
	else
		middle = string(1, s[l]);
	string suffix = prefix;
	reverse(suffix.begin(), suffix.end());
	return prefix + middle + suffix;
}
