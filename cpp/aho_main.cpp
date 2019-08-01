vector<pair<int, int>> aho_main(
	const vector<string>& P,
	const string& s
) {
	aho_node* root = new aho_node;
	for (int i=0; i<(int)P.size(); i++)
		aho_insert(root, P[i], i);
	vector<aho_node*> q = aho_find_links(root);
	aho_find_dict(q);
	aho_node* curr = root;
	vector<pair<int, int>> result;
	for (int i=1; i<=(int)s.size(); i++) {
		while (curr && !curr->next.count(s[i-1]))
			curr = curr->link;
		curr = curr ? curr->next[s[i-1]] : root;
		for (auto l = curr->dict; l; l = l->link->dict)
			result.emplace_back(l->id, i-(int)P[l->id].size());
	}
	for (auto l : q)
		delete l;
	return result;
}