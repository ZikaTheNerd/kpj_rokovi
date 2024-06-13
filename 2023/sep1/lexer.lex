%option noinput
%option nounput
%option noyywrap

%{

#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include "RegIzraz.hpp"

using namespace std;

#include "parser.tab.hpp"

%}

%%

":="                { return op_dodele; }
[\*\+\[\];\(\)\|,]         { return *yytext; }
[\[][^\]]*[\]]       {
    yylval.s = new string(yytext);
    return karak_klasa;
}
["][^"]*["]         {
    yylval.s = new string(yytext);
    return string_literal;
}
"print"             { return print_token; }

[ \t\n]             { }
[^rs]               {
    yylval.c = *yytext;
    return karakter;
}


r[0-9]+             {
    yylval.s = new string(yytext);
    return id_izraz;
}
s[0-9]+             {
    yylval.s = new string(yytext);
    return id_string;
}
.                   {
    cerr << "Leksicka greska: " << endl;
    exit(EXIT_FAILURE);
}

%%
