string trie_smallest(trie_node* t) {
	string s;
	while (!t->c) {
		s += t->next.begin()->first;
		t = t->next.begin()->second;
	}
	return s;
}
