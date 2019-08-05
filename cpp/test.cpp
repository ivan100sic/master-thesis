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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s = "abracadabra.";
	auto p = sarray_slow(s);
	cerr << sarray_find(s, p, "abra") << '\n';
	cerr << sarray_find(s, p, "aba") << '\n';
	cerr << sarray_find(s, p, "aca") << '\n';
	cerr << sarray_find(s, p, "zz") << '\n';
	cerr << sarray_find(s, p, "a") << '\n';
	cerr << sarray_find(s, p, "aaaa") << '\n';
	cerr << sarray_find(s, p, "") << '\n';
}
