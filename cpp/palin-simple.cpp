vector<pair<int, int>> palin_n2(const string& s) {
	int n = s.size();
	vector<pair<int, int>> result;
	for (int l=0, r=0; r<n; (l<r?l:r)++) {
		int x=l, y=r;
		while (x>=0 && y<n && s[x] == s[y])
			x--, y++;
		if (x+1 < y)
			result.emplace_back(x+1, y);
	}
	return result;
}
