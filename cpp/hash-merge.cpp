pair<string, string> hash_merge(long q, long M, int n) {
	vector<hash_cluster*> c(n);
	long qi = 1;
	for (int i=n-1; i>=0; i--) {
		c[i] = new hash_cluster {nullptr, nullptr, qi, i};
		qi = (__int128_t)qi * q % M;
	}
	auto cmp = [](hash_cluster* a, hash_cluster* b) {
		return a->h < b->h;
	};
	while (c.size()) {
		sort(c.begin(), c.end(), cmp);
		if (c[0]->h == 0) {
			string s(n, 'b'), p = s;
			hash_collect(c[0], p, 1);
			return {s, p};
		}
		if (c.size() == 1)
			break;
		int j = 0;
		vector<hash_cluster*> d;
		if (c.size() % 2) {
			d.push_back(c[0]);
			j++;
		}
		for (; j != (int)c.size(); j+=2) {
			auto t = new hash_cluster
				{c[j+1], c[j], c[j+1]->h - c[j]->h, 0};
			d.push_back(t);
		}
		swap(c, d);
	}
	return {"", ""};
}
