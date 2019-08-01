struct aho_node {
	map<char, aho_node*> next;
	int id;
	aho_node* link;
	aho_node* dict;
	aho_node() : id(-1), link(nullptr), dict(nullptr) {}
};
