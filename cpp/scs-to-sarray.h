template<class T>
vector<int> sarray_scs(const string& s, T func) {
	vector<int> v = func(s + '\0');
	v.erase(v.begin());
	return v;
}
