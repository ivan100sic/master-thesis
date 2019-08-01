string trie_lb(trie_node* root, const string& s) {
	int n = s.size();
	trie_node* t = root;
	vector<trie_node*> path = {t};
	for (int i=0; i<n; i++) {
		char x = s[i];
		if (t->next.count(x)) {
			t = t->next[x];
			path.push_back(t);
		} else {
			for (int j=i; j>=0; j--) {
				if (auto it = path[j]->next.upper_bound(s[j]);
					it != path[j]->next.end())
				{
					return s.substr(0, j) + it->first +
						trie_smallest(it->second);
				}
			}
			return "";
		}
	}
	return s + trie_smallest(t);
}
