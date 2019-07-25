#include <bits/stdc++.h>
using namespace std;

vector<int> naive_search(const string& s, const string& p);
vector<int> kmp_ff(const string& p);
vector<int> kmp_main(const string& s, const string& p);
vector<int> kmp_simple(const string& s, const string& p);
vector<int> z_algorithm(const string& s, const string& p);