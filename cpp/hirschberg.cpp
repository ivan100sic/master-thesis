string hirschberg(const string& s, const string& p) {
	if (s.size() > p.size())
		return hirschberg(p, s);
	int n = s.size(), m = p.size();
	if (n == 0)
		return string();
	if (n == 1) {
		if (p.find(s[0]) != string::npos)
			return string(1, s[0]);
		else
			return string();
	}
	string s1 = s.substr(0, n/2), s2 = s.substr(n/2);
	string p_rev = p, s2_rev = s2;
	reverse(p_rev.begin(), p_rev.end());
	reverse(s2_rev.begin(), s2_rev.end());
	vector<int> v1 = lcs_vector(s1, p);
	vector<int> v2 = lcs_vector(s2_rev, p_rev);
	int i_best = 0;
	for (int i=1; i<=m; i++)
		if (v1[i] + v2[m-i] > v1[i_best] + v2[m-i_best])
			i_best = i;
	return hirschberg(s1, p.substr(0, i_best))
	     + hirschberg(s2, p.substr(i_best));
}
