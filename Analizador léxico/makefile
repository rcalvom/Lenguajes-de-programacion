CC = g++

all:
	$(CC) -Ilibs -Isrc libs/deterministic_finite_automaton.cpp libs/state.cpp src/main.cpp src/lexical_analizer.cpp -o build/main

build_test:
	$(CC) -Ilibs libs/deterministic_finite_automaton.cpp libs/state.cpp test/dfa.cpp -o build/test_dfa

run:
	@./build/main