CXX = g++

all: build

build: libs/deterministic_finite_automaton.cpp libs/state.cpp src/main.cpp src/lexical_analizer.cpp src/token.cpp
	$(CXX) -Ilibs -Isrc libs/deterministic_finite_automaton.cpp libs/state.cpp src/main.cpp src/lexical_analizer.cpp src/token.cpp -o executable/main

build_test:
	$(CXX) -Ilibs libs/deterministic_finite_automaton.cpp libs/state.cpp test/dfa.cpp -o executable/test_dfa

run:
	@./executable/main