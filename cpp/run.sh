g++ -pipe -std=c++17 -O2 -include header.h test.cpp $1 -o test && ./test && rm test
# g++ -pipe -std=c++17 -g -include header.h test.cpp $1 -o test && ./test
