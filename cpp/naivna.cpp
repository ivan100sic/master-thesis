vector<int> naive_search(const string& s, const string& p) {
	int n = s.size(), m = p.size();
	vector<int> result;
	for (int i=0; i<=n-m; i++) {
		bool ok = true;
		for (int j=0; j<m; j++) {
			if (s[i+j] != p[j]) {
				ok = false;
				break;
			}
		}
		if (ok)
			result.push_back(i);
	}
	return result;
}
