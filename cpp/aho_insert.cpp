void aho_insert(aho_node* root, const string& s, int id) {
	aho_node* t = root;
	for (char x : s)
		if (t->next.count(x))
			t = t->next[x];
		else
			t = t->next[x] = new aho_node;
	t->id = id;
}
