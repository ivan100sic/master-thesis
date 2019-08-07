typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace chrono;
struct stopwatch {
	typedef time_point<high_resolution_clock> tp;

	tp last_tick;
	bool notock = false;

	void tick() {
		last_tick = high_resolution_clock::now();
	}

	void tock() const {
		duration<double> dur = high_resolution_clock::now() - last_tick;
		cerr << "Time: " << dur.count() << '\n';
	}

	stopwatch() {
		tick();
	}

	stopwatch(int) {
		tick();
		notock = true;
	}

	~stopwatch() {
		if (!notock) {
			tock();
		}
	}
};

int treesize(stree_node* p) {
	vector<stree_node*> q = {p};
	size_t qs = 0;
	while (qs != q.size()) {
		auto x = q[qs++];
		for (auto [y, z] : x->next)
			q.push_back(z);
	}
	return q.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	stopwatch sw;
	mt19937 eng;

	string s;
	for (int i=0; i<200000; i++)
		s += uniform_int_distribution<char>('a', 'b')(eng);
	cerr << s.size() << '\n';
	auto p = sarray_scs(s, scs_faster);
	auto q = lcp_array(s, p);
	auto t = suffix_tree(s, p, q);

	auto r1 = stree_find_all(t, s, "abbababb");

	for (int i=0; i<100000; i++) {
		stree_find_all(t, s, "abbababb");
	}


	auto r2 = kmp_simple(s, "abbababb");

	sort(r1.begin(), r1.end());

	for (int x : r1)
		cerr << x << ' ';
	cerr << '\n';

	for (int x : r2)
		cerr << x << ' ';
	cerr << '\n';

	cerr << (r1 == r2) << '\n';
}
