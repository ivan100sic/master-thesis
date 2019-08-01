pair<bool, string> aho_node_to_str_impl(aho_node* root, aho_node* tgt, string p) {
	if (root == tgt)
		return {true, p};
	for (auto [x, y] : root->next) {
		auto result = aho_node_to_str_impl(y, tgt, p+x);
		if (result.first)
			return result;
	}
	return {false, ""};
}

string aho_node_to_str(aho_node* root, aho_node* tgt) {
	if (!root || !tgt)
		return "";
	return aho_node_to_str_impl(root, tgt, "").second;
}

aho_node* aho_find(aho_node* root, string p) {
	for (char x : p) {
		if (root->next.count(x)) {
			root = root->next[x];
		} else {
			return nullptr;
		}
	}
	return root;
}