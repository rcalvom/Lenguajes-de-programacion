CXX = g++

all: 

build:  Syntactic_Analyzer/libs/deterministic_finite_automaton/deterministic_finite_automaton.cpp Syntactic_Analyzer/libs/deterministic_finite_automaton/state.cpp Syntactic_Analyzer/libs/grammar/production_rule.cpp Syntactic_Analyzer/libs/lexical_analyzer/lexical_analizer.cpp Syntactic_Analyzer/libs/lexical_analyzer/token.cpp Syntactic_Analyzer/libs/syntactic_analyzer/syntactic_analyzer.cpp Syntactic_Analyzer/src/main.cpp
	$(CXX) -ISyntactic_Analyzer/libs/deterministic_finite_automaton Syntactic_Analyzer/libs/deterministic_finite_automaton/deterministic_finite_automaton.cpp Syntactic_Analyzer/libs/deterministic_finite_automaton/state.cpp -ISyntactic_Analyzer/libs/grammar Syntactic_Analyzer/libs/grammar/grammar.cpp Syntactic_Analyzer/libs/grammar/production_rule.cpp -ISyntactic_Analyzer/libs/lexical_analyzer Syntactic_Analyzer/libs/lexical_analyzer/lexical_analizer.cpp Syntactic_Analyzer/libs/lexical_analyzer/token.cpp -ISyntactic_Analyzer/libs/syntactic_analyzer Syntactic_Analyzer/libs/syntactic_analyzer/syntactic_analyzer.cpp Syntactic_Analyzer/src/main.cpp -o Syntactic_Analyzer/build/main

test: 
	$(CXX) -ISyntactic_Analyzer/libs/deterministic_finite_automaton Syntactic_Analyzer/libs/deterministic_finite_automaton/deterministic_finite_automaton.cpp Syntactic_Analyzer/libs/deterministic_finite_automaton/state.cpp -ISyntactic_Analyzer/libs/grammar Syntactic_Analyzer/libs/grammar/grammar.cpp Syntactic_Analyzer/libs/grammar/production_rule.cpp -ISyntactic_Analyzer/libs/lexical_analyzer Syntactic_Analyzer/libs/lexical_analyzer/lexical_analizer.cpp Syntactic_Analyzer/libs/lexical_analyzer/token.cpp -ISyntactic_Analyzer/libs/syntactic_analyzer Syntactic_Analyzer/libs/syntactic_analyzer/syntactic_analyzer.cpp Syntactic_Analyzer/test/test.cpp -o Syntactic_Analyzer/build/test
	@./Syntactic_Analyzer/build/test

run:
	@./Syntactic_Analyzer/build/main