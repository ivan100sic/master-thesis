int trie_count(trie_node* root, const string& s) {
	trie_node* t = root;
	for (char x : s)
		if (t->next.count(x))
			t = t->next[x];
		else
			return 0;
	return t->c;
}