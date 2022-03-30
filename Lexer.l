%{
    #include "Tokens.h"
%}

%option c++
%option outfile="Lexer.cpp"
%option noyywrap

RESERVED          "continue"|"else"|"inline"|"do"|"selectany"|"typedef"|"typename"|"this"|"uuid"|"case"|"using"|"switch"|"new"|"thread"|"template"|"typeid"|"static_cast"|"break"|"class"|"default"|"for"|"friend"|"mutable"|"virtual"|"goto"|"throw"|"enum"|"sizeof"|"return"|"delete"|"while"|"namespace"|"catch"|"if"|"try"|"value"|"noinline"|"safecast"|"sealed""inline"|"do"|"selectany"|"typedef"|"typename"|"this"|"uuid"|"case"|"using"|"switch"|"new"|"thread"|"template"|"typeid"|"static_cast"|"break"|"class"|"default"|"for"|"friend"|"mutable"|"virtual"|"goto"|"throw"|"enum"|"sizeof"|"return"|"delete"|"while"|"namespace"|"catch"|"if"|"try"|"value"|"noinline"|"safecast"|"sealed"|"defined"|"elif"|"and"|"or"|"in"|"def"|"except"|"import"|"from"|"as"

TYPES             "static"|"struct"|"union"|"volatile"|"register"|"extern"|"const"|"signed"|"unsigned"|"bool"|"char"|"double"|"int"|"long"|"float"|"short"|"void"|"public"|"protected"|"private"|"explicit"|"export"|"wchar_t"

PREPROCESOR       "#define"|"#elif"|"#else"|"#endif"|"#error"|"#ifdef"|"#ifndef"|"#if"|"#import"|"#include"|"#line"|"#pragma"|"#undef"|"#using"

OPERATOR           "="|"=="|"!="|"."|">"|"<"|"!"|"~"|"?"|"+"|"++"|"-"|"--"|"*"|"/"|"&"|"|"|"^"|">>"|"<<"|"%"|"+="|"-="|"*="|"/="|"//"|"=>"|"||"|"&&"|"::"|"->"

BOOLEANS            "True"|"true"|"False"|"false"

GROUPING          "("|")"|"["|"]"|"{"|"}"

%%

{PREPROCESOR}                                                                 return PREPROCESOR;
{RESERVED}                                                                    return RESERVED;  
{TYPES}                                                                       return TYPES; 
{OPERATOR}                                                                    return OPERATOR;
{BOOLEANS}                                                                    return BOOLEAN;
{GROUPING}                                                                    return GROUPING;
"/"\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/"                                 return MULTICOMMENT;
\"([^"\\]|\\.|\\\n)*\"|\'([^'\\]|\\.|\\\n)*\'|\`([^`\\]|\\.|\\\n)*\`          return STRING;
([a-zA-Z_{1}][a-zA-Z0-9_]*)/\(                                                return FUNCTIONS;
[A-Z][0-9a-zA-Z_]*                                                            return CLASS;
[_a-zA-Z][_a-zA-Z0-9]+                                                        return IDENTIFIER;
\<([^><\\]|\\.|\\\n)*\>$                                                      return PACKAGES;
"//".*                                                                        return COMMENT;
([0-9]+[.])?[0-9]+                                                            return NUMBER;
"\n"                                                                          return NEWLINE;
\t|"    "                                                                     return TAB;
.                                                                             return DEFAULT;

%%