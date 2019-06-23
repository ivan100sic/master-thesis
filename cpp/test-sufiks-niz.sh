# chrt -r 99 bash test-sufiks-niz.sh
echo -n > sir_rezultat.txt
for algo in 0 1 2
do
	for n in 30000 100000 300000
	do
		for tip in 0 1 2 3 4 5 6
		do
			echo $tip $n $algo
			./sufiks_niz $tip $n $algo >> sir_rezultat.txt
			./sufiks_niz $tip $n $algo >> sir_rezultat.txt
			./sufiks_niz $tip $n $algo >> sir_rezultat.txt
		done
	done
done
