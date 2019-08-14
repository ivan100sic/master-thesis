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

long prefixhashl(const string& s, long q, long m) {
	long h = 0;
	for (char x : s)
		h = ((__int128_t)h * q + x) % m;
	return h;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	stopwatch sw;

	const long q0 = 314159265;
	const long M = (1ll << 61) - 1;
	const int n = 4000;

	int ok = 0;
	for (int i=0; i<1000; i++) {
		auto [s, p] = hash_merge(q0+i, M, n);
		// cerr << s << '\n';
		// cerr << p << '\n';
		// cerr << prefixhashl(s, q, M) << '\n';
		// cerr << prefixhashl(p, q, M) << '\n';
		if (p.size())
			ok++;
	}
	cerr << ok << "/1000\n";
}
