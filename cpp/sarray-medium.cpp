vector<int> scs_fast(const string& s) {
	int n = s.size();
	vector<int> c(s.begin(), s.end());
	for (int h=1; h<n; h*=2) {
		vector<array<int, 3>> t(n);
		for (int i=0; i<n; i++)
			t[i] = {c[i], c[(i+h)%n], i};
		sort(t.begin(), t.end());
		vector<int> cnew(n);
		cnew[t[0][2]] = 0;
		int numc = 1;
		for (int i=1; i<n; i++)
			if (t[i][0] == t[i-1][0] && t[i][1] == t[i-1][1])
				cnew[t[i][2]] = numc-1;
			else
				cnew[t[i][2]] = numc++;
		swap(c, cnew);
	}
	vector<pair<int, int>> g(n);
	for (int i=0; i<n; i++)
		g[i] = {c[i], i};
	sort(g.begin(), g.end());
	vector<int> p(n);
	for (int i=0; i<n; i++)
		p[i] = g[i].second;
	return p;
}
