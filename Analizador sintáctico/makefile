CXX = g++

all: build

build:  libs/deterministic_finite_automaton/deterministic_finite_automaton.cpp libs/deterministic_finite_automaton/state.cpp libs/grammar/production_rule.cpp libs/lexical_analyzer/lexical_analizer.cpp libs/lexical_analyzer/token.cpp libs/syntactic_analyzer/syntactic_analyzer.cpp src/main.cpp
	$(CXX) -Ilibs/deterministic_finite_automaton libs/deterministic_finite_automaton/deterministic_finite_automaton.cpp libs/deterministic_finite_automaton/state.cpp -Ilibs/grammar libs/grammar/grammar.cpp libs/grammar/production_rule.cpp -Ilibs/lexical_analyzer libs/lexical_analyzer/lexical_analizer.cpp libs/lexical_analyzer/token.cpp -Ilibs/syntactic_analyzer libs/syntactic_analyzer/syntactic_analyzer.cpp src/main.cpp -Isrc -o executable/main

build_test: 
	$(CXX) -Ilibs/deterministic_finite_automaton libs/deterministic_finite_automaton/deterministic_finite_automaton.cpp libs/deterministic_finite_automaton/state.cpp -Ilibs/grammar libs/grammar/grammar.cpp libs/grammar/production_rule.cpp -Ilibs/lexical_analyzer libs/lexical_analyzer/lexical_analizer.cpp libs/lexical_analyzer/token.cpp -Ilibs/syntactic_analyzer libs/syntactic_analyzer/syntactic_analyzer.cpp test/test.cpp -Isrc -o executable/test
	@./executable/test

run:
	@./executable/main