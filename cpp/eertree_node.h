struct eertree_node {
	int len;
	eertree_node* link;
	map<char, eertree_node*> next;
};
