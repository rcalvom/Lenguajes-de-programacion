CC = g++

all: build

build:
	$(CC) -Ilibs libs/deterministic_finite_automaton.cpp libs/dfa_state.cpp src/main.cpp -o build/main

build_test:
	$(CC) -Ilibs libs/deterministic_finite_automaton.cpp libs/dfa_state.cpp test/dfa.cpp -o build/test_dfa

run:
	@./main