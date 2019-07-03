from collections import defaultdict

ks = defaultdict(lambda: +1e30)
lp = defaultdict(lambda: +1e30)
sr = defaultdict(lambda: +1e30)

lens = [20000, 40000, 80000, 160000, 320000]

try:
	while True:
		t, n, s = map(int, input().split())
		input()
		w = float(input().split()[-1])
		ks[t, n, s] = min(ks[t, n, s], w)

		input()
		w = float(input().split()[-1])
		lp[t, n] = min(lp[n, s], w)
		
		input()
		w = float(input().split()[-1])
		sr[t, n] = min(sr[n, s], w)
		
		input()
except:
	pass

for t in range(7):
	for s in range(3):
		print('\\hline')
		print(['$O(n^2 \\log n)$', '$O(n \\log^2 n)$', '$O(n \\log n)$'][s], end=' & ')
		for n in lens:
			print('%.3f' % ks[t, n, s], end='')
			if n < lens[-1]:
				print(' & ', end='')
			else:
				print('  \\\\')
	print()
print()

for t in range(7):
	print('\\hline')
	print(t+1, end=' & ')
	for n in lens:
		print('%.3f' % (lp[t, n] * 1000), end='')
		if n < lens[-1]:
			print(' & ', end='')
		else:
			print('  \\\\')
print()

for t in range(7):
	print('\\hline')
	print(t+1, end=' & ')
	for n in lens:
		print('%.3f' % (sr[t, n] * 1000), end='')
		if n < lens[-1]:
			print(' & ', end='')
		else:
			print('  \\\\')
print()