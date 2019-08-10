using node = sautomaton_node;
node* sautomaton_extend(node* root, node* last, char x) {
	node* curr = new node{last->len+1, nullptr, {}};
	node* p = last;
	for (; p && !p->next.count(x); p = p->link)
		p->next[x] = curr;
	if (!p) {
		curr->link = root;
	} else {
		node* q = p->next[x];
		if (p->len + 1 == q->len) {
			curr->link = q;
		} else {
			node* clone = new node(*q);
			clone->len = p->len + 1;
			for (; p && p->next[x] == q; p = p->link)
				p->next[x] = clone;
			curr->link = q->link = clone;
		}
	}
	return curr;
}
