CXX = g++
CXX_FLAGS = -Wall -Werror -Wextra -pedantic -g

izvrsni: lex.yy.o parser.tab.o RegIzraz.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

RegIzraz.o: RegIzraz.cpp RegIzraz.hpp
	$(CXX) $(CXX_FLAGS) -c $<
parser.tab.o: parser.tab.cpp parser.tab.hpp RegIzraz.hpp
	$(CXX) $(CXX_FLAGS) -c $<
lex.yy.o: lex.yy.c parser.tab.hpp RegIzraz.hpp
	$(CXX) $(CXX_FLAGS) -c $<
parser.tab.cpp parser.tab.hpp: parser.ypp RegIzraz.hpp
	bison -v -d $<
lex.yy.c: lexer.lex RegIzraz.hpp
	flex $<

.PHONY: clean
clean:
	rm -rvf lex.yy.* parser.tab.* *.o parser.output izvrsni
