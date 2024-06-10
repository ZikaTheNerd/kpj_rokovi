%option noinput
%option nounput
%option noyywrap

%{

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#include "parser.tab.hpp"

%}

%%

[{},;=x*+\.\-()]                 { return *yytext; }
"Vector<double>"            { return vektor_tip; }
"print"                     { return print_token; }
"coordinateMul"                     { return coord_token; }
"duplicate"                     { return dupl_token; }
(-)?([0-9]+[.])?[0-9]+      { 
    yylval.d = atof(yytext);
    return konstanta; 
}

[_a-zA-Z][_a-zA-Z0-9]*      { 
    yylval.s = new string(yytext);
    return id; 
}
"//".*                       { }
[ \t\n]                     { }

%%
