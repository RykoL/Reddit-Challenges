all: eratosthenes testSort

eratosthenes: clean
	g++ eratosthenes.cpp -Wall -std=c++11 -o eratosthenes
	./eratosthenes 100 -o

clean:
	if [ -e eratosthenes ]; then rm eratosthenes; fi

testSort:
	if [ -e test-sort ]; then rm test-sort; fi
	g++ testSort.cpp -Wall -std=c++11 -o test-sort
	./test-sort