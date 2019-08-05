vector<int> scs_faster(const string& s) {
	int n = s.size(), k = 256, sz = 0;
	vector<int> p(n), c(s.begin(), s.end());
	vector<vector<int>> g(max(n, k));
	for (int i=0; i<n; i++)
		g[c[i]].push_back(i);
	for (auto& gr : g) {
		for (int i : gr)
			p[sz++] = i;
		gr.clear();
	}
	for (int h=1; h<n; h*=2) {
		vector<int> pnew(n), cnew(n);
		for (int j : p) {
			int jp = (j+n-h)%n;
			g[c[jp]].push_back(jp);
		}
		sz = 0;
		for (auto& gr : g) {
			for (int i : gr)
				pnew[sz++] = i;
			gr.clear();
		}
		cnew[pnew[0]] = 0;
		int numc = 1;
		for (int i=1; i<n; i++) {
			int s0 = pnew[i-1], s1 = pnew[i];
			if (c[s1] == c[s0] && c[(s1+h)%n] == c[(s0+h)%n])
				cnew[s1] = numc-1;
			else
				cnew[s1] = numc++;
		}
		swap(c, cnew);
		swap(p, pnew);
	}
	return p;
}
