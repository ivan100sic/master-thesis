vector<int> z_algorithm(const string& s, const string& p) {
	int n = s.size(), m = p.size();
	string q = p + s;
	vector<int> z(n+m, 0), result;
	for (int i=1, l=0, r=0; i<n+m; i++) {
		if (i < r)
			z[i] = min(z[i-l], r-i);
		while (i+z[i] < n+m && q[i+z[i]] == q[z[i]])
			z[i]++;
		if (i+z[i] > r)
			l = i, r = i+z[i];
		if (z[i] >= m)
			result.push_back(i-m);
	}
	return result;
}
