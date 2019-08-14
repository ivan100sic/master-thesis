int modpow(int x, int k, int m) {
	if (k == 0)
		return 1 % m;
	int y = modpow(x, k >> 1, m);
	y = 1ll * y * y % m;
	if (k & 1)
		y = 1ll * y * x % m;
	return y;
}
