#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <chrono>
#include <random>
#include <iomanip>
using namespace std;
using namespace chrono;

mt19937 random_gen;

struct stoperica {
	time_point<high_resolution_clock> pocetak;

	stoperica() {
		pocetak = high_resolution_clock::now();
	}

	~stoperica() {
		duration<double> dur = high_resolution_clock::now() - pocetak;
		cerr << fixed << setprecision(9);
		cerr << "Vreme (s): " << dur.count() << '\n';
	}
};

struct uporedi_sufikse {
	const string& str;

	uporedi_sufikse(const string& str) : str(str) {}

	bool operator() (int u, int v) const {
		const int n = str.size();

		if (u == v)
			return false;
		while (u < n && v < n && str[u] == str[v])
			u++, v++;

		if (u == n || v == n)
			return u > v;
		else
			return str[u] < str[v];
	}
};

vector<int> sufiks_niz_n2logn(const string& str) {
	const int n = str.size();
	vector<int> sufiks_niz(n);
	for (int i=0; i<n; i++)
		sufiks_niz[i] = i;

	sort(sufiks_niz.begin(), sufiks_niz.end(),
		uporedi_sufikse(str));

	return sufiks_niz;
}

vector<int> sortiraj_ciklicne_pomeraje_nlog2n(const string& str) {
	const int n = str.size();
	const int k = 256; // velicina alfabeta
	vector<int> klasa(n);

	// Inicijalizacija
	for (int i=0; i<n; i++) {
		klasa[i] = str[i];
	}

	// Udvajanje
	for (int h=1; h<n; h*=2) {
		vector<tuple<int, int, int>> parovi(n);
		for (int i=0; i<n; i++) {
			parovi[i] = {klasa[i], klasa[(i+h)%n], i};
		}
		sort(parovi.begin(), parovi.end());

		vector<int> nova_klasa(n);
		nova_klasa[get<2>(parovi[0])] = 0;
		int broj_klasa = 1;

		for (int i=1; i<n; i++) {
			if (get<0>(parovi[i]) == get<0>(parovi[i-1]) &&
				get<1>(parovi[i]) == get<1>(parovi[i-1]))
			{
				nova_klasa[get<2>(parovi[i])] = broj_klasa-1;
			} else {
				nova_klasa[get<2>(parovi[i])] = broj_klasa++;
			}
		}

		swap(klasa, nova_klasa);
	}

	vector<int> niz(n);
	vector<vector<int>> grupe(max(n, k));
	for (int i=0; i<n; i++) {
		grupe[klasa[i]].push_back(i);
	}
	int kraj = 0;
	for (const auto& grupa : grupe) {
		for (int sufiks : grupa) {
			niz[kraj++] = sufiks;
		}
	}
	return niz;
}

vector<int> sortiraj_ciklicne_pomeraje_nlogn(const string& str) {
	const int n = str.size();
	const int k = 256;
	vector<int> niz(n);
	vector<int> klasa(n);
	vector<vector<int>> grupe(max(n, k));

	// Inicijalizacija
	for (int i=0; i<n; i++) {
		klasa[i] = str[i];
		grupe[str[i]].push_back(i);
	}

	int kraj = 0;
	for (auto& grupa : grupe) {
		for (int sufiks : grupa) {
			niz[kraj++] = sufiks;
		}
		grupa.clear();
	}

	// Udvajanje
	for (int h=1; h<n; h*=2) {
		vector<int> novi_niz(n);
		vector<int> nova_klasa(n);

		for (int i=0; i<n; i++) {
			int sufiks = niz[i];
			int pomeren = (sufiks+n-h)%n;
			grupe[klasa[pomeren]].push_back(pomeren);
		}

		kraj = 0;
		for (auto& grupa : grupe) {
			for (int sufiks : grupa) {
				novi_niz[kraj++] = sufiks;
			}
			grupa.clear();
		}

		nova_klasa[novi_niz[0]] = 0;
		int broj_klasa = 1;

		for (int i=1; i<n; i++) {
			int sufiks_sad = novi_niz[i];
			int sufiks_pre = novi_niz[i-1];
			if (klasa[sufiks_sad] == klasa[sufiks_pre] &&
				klasa[(sufiks_sad+h)%n] == klasa[(sufiks_pre+h)%n])
			{
				nova_klasa[sufiks_sad] = broj_klasa-1;
			} else {
				nova_klasa[sufiks_sad] = broj_klasa++;
			}
		}

		swap(klasa, nova_klasa);
		swap(niz, novi_niz);
	}

	return niz;
}

template<class F>
vector<int> sufiks_niz_brzi(
	const string& str,
	F sorter_ciklicnih_pomeraja
) {
	string prosirenje = str + '\0';
	auto sortiran = sorter_ciklicnih_pomeraja(prosirenje);
	sortiran.erase(sortiran.begin());
	return sortiran;
}

vector<int> nadji_lcp_niz(
	const string& str,
	const vector<int>& sufiks_niz
) {
	const int n = str.size();
	vector<int> lcp(n-1);
	vector<int> rang(n);
	
	for (int i=0; i<n; i++) {
		rang[sufiks_niz[i]] = i;
	}

	int k = 0;
	for (int i=0; i<n; i++) {
		if (rang[i] != n-1) {
			int j = sufiks_niz[rang[i] + 1];
			while (i+k < n && j+k < n && str[i+k] == str[j+k])
				k++;
			lcp[rang[i]] = k;
			k = max(0, k-1);
		} else {
			k = 0;
		}
	}

	return lcp;
}

string test_primer(int tip, int n) {
	string str(n, 0);

	if (tip == 0) {
		for (int i=0; i<n; i++)
			str[i] = 'a';
	} else if (tip == 1) {
		uniform_int_distribution<char> slovo('a', 'z');
		for (int i=0; i<n; i++)
			str[i] = slovo(random_gen);
	} else if (tip == 2) {
		uniform_int_distribution<char> slovo('a', 'b');
		for (int i=0; i<n; i++)
			str[i] = slovo(random_gen);
	} else if (tip == 3) {
		for (int i=0; i<n; i++)
			str[i] = 'a' + i%2;
	} else if (tip == 4) {
		for (int i=0; i<n; i++)
			str[i] = 'a';
		for (int i=0; i*i<n; i++)
			str[i*i] = 'b';
	}

	return str;
}

int trazi(
	const string& str,
	const vector<int>& sufiks_niz,
	const vector<int>& lcp_niz,
	const string& podstr
) {
	const int n = str.size();
	const int m = podstr.size();
	int l = 0, r = n-1, o = n;

	while (l < r) {
		const int sred = (l+r) >> 1;
		const int j = sufiks_niz[sred];
		int k = 0;

		while (j+k < n && k < m && str[j+k] == podstr[k])
			k++;
		
		if (k == m || (j+k < n && str[j+k] > podstr[k])) {
			o = sred;
			r = sred - 1;
		} else {
			l = sred + 1;
		}
	}

	return o;
}

int main(int argc, char** argv) {
	if (argc < 4)
		return 0;
	const int tip = stoi(argv[1]);
	const int n = stoi(argv[2]);
	const int sufiks_niz_algoritam = stoi(argv[3]);

	string str = test_primer(tip, n);

	vector<int> sufiks_niz;
	vector<int> lcp_niz;

	{
		cerr << "Konstrukcija sufiks niza...\n";
		stoperica st;
		if (sufiks_niz_algoritam == 0) {
			sufiks_niz = sufiks_niz_n2logn(str);
		} else if (sufiks_niz_algoritam == 1) {
			sufiks_niz = sufiks_niz_brzi(str,
				sortiraj_ciklicne_pomeraje_nlog2n);
		} else if (sufiks_niz_algoritam == 2) {
			sufiks_niz = sufiks_niz_brzi(str,
				sortiraj_ciklicne_pomeraje_nlogn);
		}
	}

	{
		cerr << "Konstrukcija LCP niza...\n";
		stoperica st;
		lcp_niz = nadji_lcp_niz(str, sufiks_niz);
	}

	{
		cerr << "Pretraga nasumicnih podstringova...\n";
		stoperica st;

		const int DUZINA = 100;
		uniform_int_distribution<int> pozicija(0, n-DUZINA);

		for (int i=0; i<n; i++) {
			const int j = pozicija(random_gen);
			const string podstr = str.substr(j, DUZINA);
			trazi(str, sufiks_niz, lcp_niz, podstr);
		}
	}
}