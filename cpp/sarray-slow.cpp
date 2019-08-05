vector<int> sarray_slow(const string& s) {
	int n = s.size();
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), suffix_cmp(s));
	return p;
}
