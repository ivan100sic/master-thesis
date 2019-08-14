void hash_collect(hash_cluster* root, string& s, int sgn) {
	if (root->l) {
		hash_collect(root->l, s, sgn);
		hash_collect(root->r, s, -sgn);
	} else {
		s[root->id] = 'b' + sgn;
	}
}
