using node = stree_node;
vector<int> stree_find_all(
	node* root,
	const string& s,
	const string& t
) {
	vector<int> result;
	node* curr = root;
	int pos = 0;
	for (char x : t)
		if (pos == curr->r) {
			if (!curr->next.count(x))
				return result;
			curr = curr->next[x];
			pos = curr->l + 1;
		} else if (x != s[pos])
			return result;
		else
			pos++;
	vector<node*> q = {curr};
	size_t qs = 0;
	while (qs != q.size()) {
		node* tmp = q[qs++];
		if (tmp->id != -1)
			result.push_back(tmp->id);
		for (auto [x, ch] : tmp->next)
			q.push_back(ch);
	}
	return result;
}
