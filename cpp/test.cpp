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

int count_eertree(const string& s) {
	auto p = eertree(s);
	int z = 0;
	for (auto q : p) {
		// cerr << "* " << q->len << '\n';
		while (q->len > 0) {
			z++;
			q = q->link;
			// cerr << "  * " << q->len << '\n';
		}
	}
	return z;
}

int count_manacher(const string& s) {
	auto v = manacher(s);
	int z = 0;
	for (auto [l, r] : v)
		z += (r-l+1)/2;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	mt19937 eng;

	string s;
	for (int i=0; i<100000; i++) {
		s += uniform_int_distribution<char>('a', 'b')(eng);
	}

	// s = "aabaa";

	cerr << count_eertree(s) << '\n';
	cerr << count_manacher(s) << '\n';
}
