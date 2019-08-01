void aho_find_dict(const vector<aho_node*>& q) {
	int L = q.size();
	q[0]->dict = nullptr;
	for (int i=1; i<L; i++)
		if (q[i]->id != -1)
			q[i]->dict = q[i];
		else
			q[i]->dict = q[i]->link->dict;
}
