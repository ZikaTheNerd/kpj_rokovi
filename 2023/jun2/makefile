CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -g

izvrsni: parser.tab.o lex.yy.o complex.o naredbe.o
	$(CXX) $(CXXFLAGS) -o $@ $^

parser.tab.o: parser.tab.cpp parser.tab.hpp complex.hpp naredbe.hpp
	$(CXX) $(CXXFLAGS) -c $<

lex.yy.o: lex.yy.c parser.tab.hpp complex.hpp naredbe.hpp
	$(CXX) $(CXXFLAGS) -c $<

complex.o: complex.cpp complex.hpp naredbe.hpp
	$(CXX) $(CXXFLAGS) -c $<

naredbe.o: naredbe.cpp naredbe.hpp complex.hpp
	$(CXX) $(CXXFLAGS) -c $<

parser.tab.cpp parser.tab.hpp: parser.ypp complex.hpp naredbe.hpp
	bison -v -d $< 

lex.yy.c: lexer.lex
	flex $<

.PHONY: clean
clean:
	rm -rvf *.o parser.tab.hpp lex.yy.* 
