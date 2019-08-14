vector<pair<int, int>> manacher(const string& s) {
	int n = s.size(), m = 2*n+1;
	string p = "$";
	for (int i=0; i<n; i++)
		p += s[i], p += '$';
	vector<int> q(m, 0);
	vector<pair<int, int>> result;
	for (int i=1, l=0, r=0; i<m-1; i++) {
		if (i < r)
			q[i] = min(q[r+l-i], r-i);
		while (q[i] <= i && i+q[i] < m && p[i-q[i]] == p[i+q[i]])
			q[i]++;
		q[i]--;
		if (i+q[i] > r) {
			r = i + q[i];
			l = i - q[i];
		}
		if (q[i] > 0)
			result.emplace_back((i-q[i])/2, (i+q[i])/2);
	}
	return result;
}
