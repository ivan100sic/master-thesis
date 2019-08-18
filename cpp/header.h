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
#include "trie_node.h"
void trie_insert(trie_node* root, const string& s);
int trie_count(trie_node* root, const string& s);
string trie_smallest(trie_node* root);
string trie_lb(trie_node* root, const string& s);
#include "aho_node.h"
void aho_insert(aho_node* root, const string& s, int id);
vector<aho_node*> aho_find_links(aho_node* root);
pair<bool, string> aho_node_to_str_impl(aho_node* root, aho_node* tgt, string p);
string aho_node_to_str(aho_node* root, aho_node* tgt);
aho_node* aho_find(aho_node* root, string p);
void aho_find_dict(const vector<aho_node*>& q);
vector<pair<int, int>> aho_main(const vector<string>& P, const string& s);
#include "sarray-slow-cmp.h"
vector<int> sarray_slow(const string& s);
vector<int> scs_fast(const string& s);
#include "scs-to-sarray.h"
vector<int> scs_faster(const string& s);
vector<int> lcp_array(const string& s, const vector<int>& p);
int sarray_lb(const string& s, const vector<int>& p, const string& t);
int sarray_find(const string& s, const vector<int>& p, const string& t);
#include "stree_node.h"
stree_node* suffix_tree(const string& s, const vector<int>& p, const vector<int>& q);
vector<int> stree_find_all(stree_node* root, const string& s, const string& t);
#include "sautomaton-node.h"
sautomaton_node* sautomaton_extend(sautomaton_node* root, sautomaton_node* last, char x);
sautomaton_node* sautomaton(const string& s);
int modpow(int x, int k, int m);
vector<int> modpowvec(int x, int k, int m);
vector<int> prefixhash(const string& s, int q, int m);
vector<int> rabin_karp(const string& s, const string& p, int q, int M);
pair<string, string> birthday1(int q, int M, int n);
#include "hash-cluster.h"
void hash_collect(hash_cluster* root, string& s, int sgn);
pair<string, string> hash_merge(long q, long M, int n);
vector<pair<int, int>> palin_n2(const string& s);
vector<pair<int, int>> manacher(const string& s);
#include "eertree_node.h"
vector<eertree_node*> eertree(const string& s);