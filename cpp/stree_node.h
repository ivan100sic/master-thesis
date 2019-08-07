struct stree_node {
	int l, r, id;
	stree_node* p;
	map<char, stree_node*> next;
	stree_node(int l, int r, int id, stree_node* p)
		: l(l), r(r), id(id), p(p) {}
};
