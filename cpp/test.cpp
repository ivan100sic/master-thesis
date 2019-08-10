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

struct node {
	int len;
	bool clone;
	node* link;
	map<char, node*> next;
	vector<node*> invlinks;
};

node* sautomaton1(const string& s) {
	vector<node*> created;
	node* root = new node {0, false, nullptr, {}, {}};
	created.push_back(root);
	auto last = root;
	for (char x : s) {
		auto curr = new node {last->len + 1, false, nullptr, {}, {}};
		created.push_back(curr);
		auto p = last;
		for (; p && !p->next.count(x); p = p->link)
			p->next[x] = curr;
		if (!p) {
			curr->link = root;
		} else {
			auto q = p->next[x];
			if (p->len + 1 == q->len) {
				curr->link = q;
			} else {
				node* clone = new node(*q);
				created.push_back(clone);
				clone->len = p->len + 1;
				clone->clone = true;
				for (; p && p->next[x] == q; p = p->link)
					p->next[x] = clone;
				q->link = curr->link = clone;
			}
		}
		last = curr;
	}

	for (node* q : created)
		if (q->link)
			q->link->invlinks.push_back(q);


	return root;
}

void dfs(node* root, vector<int>& v) {
	if (!root->clone)
		v.push_back(root->len);
	for (node* y : root->invlinks)
		dfs(y, v);
}

vector<int> nadji(node* root, const string& s) {
	for (char x : s) {
		if (!root->next.count(x))
			return {};
		root = root->next[x];
	}

	vector<int> v;
	dfs(root, v);
	for (int& x : v)
		x -= s.size();
	sort(v.begin(), v.end());
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	mt19937 eng;

	string s = "aabaabb", p, q = "waabaabbo";
	for (int i=0; i<100000; i++) {
		p += s;
		p += uniform_int_distribution<char>('a', 'z')(eng);
	}

	auto root = sautomaton1(p);
	auto v = nadji(root, q);
	auto w = kmp_simple(p, q);

	for (int x : v)
		cerr << x << ' ';
	cerr << '\n';

	for (int x : w)
		cerr << x << ' ';
	cerr << '\n';

	cerr << (v == w) << '\n';
}
