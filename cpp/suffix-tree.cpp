using node = stree_node;
node* suffix_tree(
	const string& s,
	const vector<int>& p,
	const vector<int>& q
) {
	int n = s.size();
	auto root = new node(0, 0, 0, 0);
	auto curr = root->next[s[p[0]]]
		= new node(p[0], n, p[0], root);
	for (int i=1; i<n; i++) {
		int t = q[i-1], d = n - p[i-1];
		while (d && d - t >= (curr->r - curr->l)) {
			d -= curr->r - curr->l;
			curr = curr->p;
		}
		if (d > t) {
			int m = curr->r - (d - t);
			node* mid = new node(curr->l, m, -1, curr->p);
			mid->next[s[m]] = curr;
			curr->p->next[s[curr->l]] = mid;
			curr->l = m;
			curr->p = mid;
			curr = mid;
		}
		if (p[i] + t < n)
			curr = curr->next[s[p[i] + t]]
				= new node(p[i] + t, n, p[i], curr);
	}
	return root;
}
