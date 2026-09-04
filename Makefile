all: power-digit-sum.cpp
	g++ -Wall -std=c++17 power-digit-sum.cpp -o pds
clean:
	rm -f pds
