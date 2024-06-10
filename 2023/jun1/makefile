CXX = g++
CXXFLAGS = -Wall -Wextra -g

izvrsni: lex.yy.o parser.tab.o utils.o
	$(CXX) $(CXXFLAGS) -o $@ $^
lex.yy.o: lex.yy.c parser.tab.hpp utils.hpp
	$(CXX) $(CXXFLAGS) -c $<
lex.yy.c: lexer.lex
	flex $<
parser.tab.o: parser.tab.cpp parser.tab.hpp utils.hpp 
	$(CXX) $(CXXFLAGS) -c $<
parser.tab.cpp parser.tab.hpp: parser.ypp utils.hpp 
	# -d: parser.tab.hpp
	# -v: parser.output
	bison -d -v $<
	
utils.o: utils.cpp utils.hpp
	$(CXX) $(CXXFLAGS) -c $<
.PHONY: clean
clean:
	rm -f *.o lex.yy* parser.tab* izvrsni parser.output
