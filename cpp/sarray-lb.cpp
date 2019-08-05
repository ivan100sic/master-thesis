int sarray_lb(
	const string& s,
	const vector<int>& p,
	const string& t
) {
	int n = s.size(), l = 0, r = n-1, i = n;
	while (l <= r) {
		int mid = (l+r) >> 1, j = p[mid];
		if (lexicographical_compare(
			s.begin()+j, s.end(),
			t.begin(), t.end()))
		{
			l = mid + 1;
		} else {
			i = mid;
			r = mid - 1;
		}
	}
	return i;
}
