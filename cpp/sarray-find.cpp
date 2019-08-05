int sarray_find(
	const string& s,
	const vector<int>& p,
	const string& t
) {
	int i = sarray_lb(s, p, t), n = s.size(), d = t.size();
	if (i == n)
		return -1;
	int j = p[i];
	if (j+d <= n && equal(t.begin(), t.end(), s.begin()+j))
		return j;
	return -1;
}
