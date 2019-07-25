typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i : z_algorithm("atmtamtmtmttattatatatatattmatmatatmatatatmatatatmata", "atata"))
		cerr << i << ' ';
	cerr << '\n';
}