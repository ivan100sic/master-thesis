#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <chrono>
#include <random>
#include <iomanip>
#include <bitset>
using namespace std;
using namespace chrono;

mt19937 random_gen;

struct stopwatch {
	time_point<high_resolution_clock> start;

	stopwatch() {
		start = high_resolution_clock::now();
	}

	~stopwatch() {
		duration<double> dur = high_resolution_clock::now() - start;
		cout << fixed << setprecision(9);
		cout << "Time (s): " << dur.count() << '\n';
	}
};

struct suffix_cmp {
	const string& s;

	suffix_cmp(const string& s) : s(s) {}

	bool operator() (int u, int v) const {
		const int n = s.size();

		if (u == v)
			return false;
		while (u < n && v < n && s[u] == s[v])
			u++, v++;

		if (u == n || v == n)
			return u > v;
		else
			return s[u] < s[v];
	}
};

vector<int> suffix_array_n2logn(const string& s) {
	const int n = s.size();
	vector<int> p(n);
	for (int i=0; i<n; i++)
		p[i] = i;

	sort(p.begin(), p.end(), suffix_cmp(s));
	return p;
}

vector<int> sort_cyclic_shifts_nlog2n(const string& s) {
	const int n = s.size();
	const int k = 256; // alphabet size
	vector<int> c(n);

	// Initialization
	for (int i=0; i<n; i++)
		c[i] = s[i];

	// Pairing
	for (int h=1; h<n; h*=2) {
		vector<tuple<int, int, int>> pairs(n);
		for (int i=0; i<n; i++)
			pairs[i] = {c[i], c[(i+h)%n], i};
		sort(pairs.begin(), pairs.end());

		vector<int> cnew(n);
		cnew[get<2>(pairs[0])] = 0;
		int numc = 1;

		for (int i=1; i<n; i++) {
			if (get<0>(pairs[i]) == get<0>(pairs[i-1]) &&
				get<1>(pairs[i]) == get<1>(pairs[i-1]))
			{
				cnew[get<2>(pairs[i])] = numc-1;
			} else {
				cnew[get<2>(pairs[i])] = numc++;
			}
		}

		swap(c, cnew);
	}

	vector<vector<int>> groups(max(n, k));
	for (int i=0; i<n; i++)
		groups[c[i]].push_back(i);

	vector<int> p(n);
	int sz = 0;
	for (const auto& gr : groups)
		for (int i : gr)
			p[sz++] = i;
	return p;
}

vector<int> sort_cyclic_shifts_nlogn(const string& s) {
	const int n = s.size();
	const int k = 256;
	vector<int> p(n);
	vector<int> c(n);
	vector<vector<int>> groups(max(n, k));

	// Initialization
	for (int i=0; i<n; i++) {
		c[i] = s[i];
		groups[s[i]].push_back(i);
	}

	int sz = 0;
	for (auto& gr : groups) {
		for (int i : gr) {
			p[sz++] = i;
		}
		gr.clear();
	}

	// Pairing
	for (int h=1; h<n; h*=2) {
		vector<int> pnew(n);
		vector<int> cnew(n);

		for (int i=0; i<n; i++) {
			int suff = p[i];
			int shifted = (suff+n-h)%n;
			groups[c[shifted]].push_back(shifted);
		}

		sz = 0;
		for (auto& gr : groups) {
			for (int i : gr) {
				pnew[sz++] = i;
			}
			gr.clear();
		}

		cnew[pnew[0]] = 0;
		int numc = 1;

		for (int i=1; i<n; i++) {
			int s1 = pnew[i];
			int s0 = pnew[i-1];
			if (c[s1] == c[s0] &&
				c[(s1+h)%n] == c[(s0+h)%n])
			{
				cnew[s1] = numc-1;
			} else {
				cnew[s1] = numc++;
			}
		}

		swap(c, cnew);
		swap(p, pnew);
	}

	return p;
}

template<class F>
vector<int> suffix_array_fast(
	const string& s,
	F cyclic_shifts_sorter
) {
	string s_ext = s + '\0';
	auto p = cyclic_shifts_sorter(s_ext);
	p.erase(p.begin());
	return p;
}

vector<int> construct_lcp_array(
	const string& s,
	const vector<int>& p
) {
	const int n = s.size();
	vector<int> q(n-1);
	vector<int> r(n);
	
	for (int i=0; i<n; i++)
		r[p[i]] = i;

	int k = 0;
	for (int i=0; i<n; i++) {
		if (r[i] != n-1) {
			int j = p[r[i] + 1];
			while (i+k < n && j+k < n && s[i+k] == s[j+k])
				k++;
			q[r[i]] = k;
			k = max(0, k-1);
		} else {
			k = 0;
		}
	}

	return q;
}

string testcase(int type, int n) {
	string s(n, 0);

	if (type == 0) {
		for (int i=0; i<n; i++)
			s[i] = 'a';
	} else if (type == 1) {
		uniform_int_distribution<char> letter_gen('a', 'z');
		for (int i=0; i<n; i++)
			s[i] = letter_gen(random_gen);
	} else if (type == 2) {
		uniform_int_distribution<char> letter_gen('a', 'b');
		for (int i=0; i<n; i++)
			s[i] = letter_gen(random_gen);
	} else if (type == 3) {
		for (int i=0; i<n; i++)
			s[i] = 'a' + i%2;
	} else if (type == 4) {
		for (int i=0; i<n; i++)
			s[i] = 'a';
		for (int i=0; i*i<n; i++)
			s[i*i] = 'b';
	} else if (type == 5) {
		for (int i=0; i<n; i++)
			s[i] = 'a' + bitset<32>(i).count() % 2;
	} else if (type == 6) {
		string f0 = "a", f1 = "b";
		while ((int)f1.size() < n) {
			string f2 = f0 + f1;
			swap(f0, f1);
			swap(f1, f2);
		}
		s = f1.substr(0, n);
	}

	return s;
}

int find_substring(
	const string& s,
	const vector<int>& p,
	const string& substr
) {
	const int n = s.size();
	const int m = substr.size();
	int l = 0, r = n-1, o = n;

	while (l < r) {
		const int mid = (l+r) >> 1;
		const int j = p[mid];
		int k = 0;

		while (j+k < n && k < m && s[j+k] == substr[k])
			k++;
		
		if (k == m || (j+k < n && s[j+k] > substr[k])) {
			o = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return o;
}

int main(int argc, char** argv) {
	if (argc < 4)
		return 0;

	const int type = stoi(argv[1]);
	const int n = stoi(argv[2]);
	const int suffix_array_algo = stoi(argv[3]);
	cout << type << ' ' << n << ' ' << suffix_array_algo << '\n';

	string s = testcase(type, n);
	vector<int> p, q;

	{
		cout << "Suffix array construction...\n";
		stopwatch st;
		if (suffix_array_algo == 0) {
			p = suffix_array_n2logn(s);
		} else if (suffix_array_algo == 1) {
			p = suffix_array_fast(s,
				sort_cyclic_shifts_nlog2n);
		} else if (suffix_array_algo == 2) {
			p = suffix_array_fast(s,
				sort_cyclic_shifts_nlogn);
		}
	}

	{
		cout << "LCP array construction...\n";
		stopwatch st;
		q = construct_lcp_array(s, p);
	}

	{
		cout << "Random substring search...\n";
		stopwatch st;

		const int LENGTH = 100;
		uniform_int_distribution<int> pos_rng(0, n-LENGTH);

		for (int i=0; i<n; i++) {
			int j = pos_rng(random_gen);
			string substr = s.substr(j, LENGTH);
			find_substring(s, p, substr);
		}
	}

	cout << '\n';
}