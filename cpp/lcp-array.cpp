vector<int> lcp_array(const string& s, const vector<int>& p)
{
	int n = s.size(), k = 0;
	vector<int> q(n-1), r(n);
	for (int i=0; i<n; i++)
		r[p[i]] = i;
	for (int i=0; i<n; i++) {
		if (r[i] != n-1) {
			int j = p[r[i] + 1];
			while (i+k < n && j+k < n && s[i+k] == s[j+k])
				k++;
			q[r[i]] = k;
			k = max(0, k-1);
		} else {
			k = 0;
		}
	}
	return q;
}
