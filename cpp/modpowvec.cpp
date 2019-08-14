vector<int> modpowvec(int x, int k, int m) {
	vector<int> a(k+1);
	a[0] = 1;
	for (int i=1; i<=k; i++)
		a[i] = 1ll * a[i-1] * x % m;
	return a;
}
