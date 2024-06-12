%option noinput
%option nounput
%option noyywrap

%{

#include <iostream>
#include <vector>
#include "complex.hpp"
#include "naredbe.hpp"
#include <cstdlib>

using namespace std;

#include "parser.tab.hpp"

%}


%%

"Complex"           { return complex_tip; }
"Array<Complex>"    { return array_tip; }
"Bool"              { return bool_tip; }

"conjugate"         { return conj_token; }
"print"             { return print_token; }
"if"                { return if_token; }
"else"              { return else_token; }

"=="                { return jednako; }
"!="                { return nejednako; }

"//".*              {  }
["][^"]*["]         {
    yylval.s = new string(yytext);
    return string_literal;
}

[i(),{}=+*|\.-]        { return *yytext; }
\n                     { return *yytext; }

-?[0-9]*            {
    yylval.i = atoi(yytext);
    return konstanta;
}

[_a-zA-Z][_a-zA-Z0-9]* {    
    yylval.s = new string(yytext);
    return id;
}

[ \t]               { }

.                   {

    cerr << "Leksicka greska: " << yytext << endl;
    exit(EXIT_FAILURE);

}

%%
