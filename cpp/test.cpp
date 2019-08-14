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

	string f = "babbabbaba";

	for (auto [x, y] : manacher(f))
		cerr << x << ' ' << y << '\n';

	mt19937 eng;
	int t = 100000;
	const int n = 40;

	while (t--) {
		string s(n, 0);
		for (int i=0; i<n; i++)
			s[i] = uniform_int_distribution<char>('a', 'b')(eng);
		auto u = manacher(s);
		auto v = palin_n2(s);
		if (u != v) {
			cerr << s << " error!\n";
			return 0;
		}
	}
		
}
