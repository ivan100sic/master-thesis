using node = eertree_node;
vector<node*> eertree(const string& s) {
	int n = s.size();
	node* eta = new node {-1, nullptr, {}};
	node* eps = new node {0, eta, {}};
	vector<node*> p(n+1);
	p[0] = eps;
	for (int i=1; i<=n; i++) {
		char c = s[i-1];
		node* t = p[i-1];
		while (i-t->len < 2 || s[i-t->len-2] != c)
			t = t->link;
		if (t->next.count(c)) {
			t = t->next[c];
		} else {
			node* q = t->link;
			t = t->next[c] = new node {t->len+2, nullptr, {}};
			if (!q) {
				t->link = eps;
			} else {
				while (s[i-q->len-2] != c)
					q = q->link;
				t->link = q->next[c];
			}
		}
		p[i] = t;
	}
	return p;
}
