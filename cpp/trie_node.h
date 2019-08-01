struct trie_node {
	map<char, trie_node*> next;
	int c;
	trie_node() : c(0) {}
};
