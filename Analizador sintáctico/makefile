CXX = g++

all: build

build: libs/deterministic_finite_automaton.cpp libs/state.cpp src/main.cpp src/lexical_analizer.cpp src/token.cpp
	$(CXX) -Ilibs -Isrc libs/deterministic_finite_automaton.cpp libs/state.cpp src/main.cpp src/lexical_analizer.cpp src/token.cpp -o executable/main

test_grammar:
	$(CXX) -Ilibs/grammar libs/grammar/grammar.cpp libs/grammar/production_rule.cpp test/test.cpp -o executable/test
	@./executable/test

run:
	@./executable/main