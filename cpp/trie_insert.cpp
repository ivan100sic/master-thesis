void trie_insert(trie_node* root, const string& s) {
	trie_node* t = root;
	for (char x : s)
		if (t->next.count(x))
			t = t->next[x];
		else
			t = t->next[x] = new trie_node;
	t->c++;
}
