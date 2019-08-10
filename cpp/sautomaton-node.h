struct sautomaton_node {
	int len;
	sautomaton_node* link;
	map<char, sautomaton_node*> next;
};
