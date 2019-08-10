using node = sautomaton_node;
node* sautomaton(const string& s) {
	node* root, *curr;
	root = curr = new node{0, nullptr, {}};
	for (char x : s)
		curr = sautomaton_extend(root, curr, x);
	return root;
}
