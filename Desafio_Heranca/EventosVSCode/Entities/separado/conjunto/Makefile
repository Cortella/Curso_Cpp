CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb


all: bin/main

clean:
	rm -rf bin/*

run: clean all
	clear
	./bin/main

bin/main: bin/conjunto.o src/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/conjunto.o: src/conjunto.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@


testar: clean all
	clear
	./bin/teste

bin/teste: bin/conjunto.o src/teste.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@











