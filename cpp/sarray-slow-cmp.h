struct suffix_cmp {
	const string& s;
	suffix_cmp(const string& s) : s(s) {}
	bool operator() (int u, int v) const {
		if (u == v)
			return false;
		return lexicographical_compare(
			s.begin()+u, s.end(),
			s.begin()+v, s.end());
	}
};
