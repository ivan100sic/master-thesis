vector<aho_node*> aho_find_links(aho_node* root) {
	vector<aho_node*> q = {root};
	size_t qs = 0;
	while (qs != q.size()) {
		aho_node* t = q[qs++];
		for (auto [c, p] : t->next) {
			aho_node* l = t->link;
			while (l && !l->next.count(c))
				l = l->link;
			if (l)
				p->link = l->next[c];
			else
				p->link = root;
			q.push_back(p);
		}
	}
	return q;
}
