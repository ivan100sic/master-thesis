pair<string, string> birthday1(int q, int M, int n) {
	map<int, string> d;
	mt19937 eng(q^M);
	while (1) {
		string s(n, 0);
		for (char& x : s)
			x = uniform_int_distribution<char>('a', 'z')(eng);
		int h = prefixhash(s, q, M).back();
		if (d.count(h) && d[h] != s) {
			return {d[h], s};
		} else {
			d[h] = s;
		}
	}
}
