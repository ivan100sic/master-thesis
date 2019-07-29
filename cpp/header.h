#include <bits/stdc++.h>
using namespace std;

vector<int> naive_search(const string& s, const string& p);
vector<int> kmp_ff(const string& p);
vector<int> kmp_main(const string& s, const string& p);
vector<int> kmp_simple(const string& s, const string& p);
vector<int> z_algorithm(const string& s, const string& p);
vector<vector<int>> lcp_matrix(const string& s);
int lcs_len(const string& s, const string& p);
int lcs_len_mem(const string& s, const string& p);
string lcs_string(const string& s, const string& p);
vector<int> lcs_vector(const string& s, const string& p);
string hirschberg(const string& s, const string& p);
string lpalsubseq(const string& s);
int levenshtein(const string& s, const string& p);