digit [0-9]
letter [a-zA-Z]
keyword auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
op "+"|"-"|"="|"/"|"*"|"<"|">"|"<="|">="|"!="|"%"
id {letter}({letter}|{digit})*

%%
"#".* printf("%s - Preprocessor directive\n",yytext);
"/*"[^*]*[*]+([^*/][^*]*[*]+)*[/] printf("%s - Multi line comment\n",yytext);
"{" printf("%s - Block Opening\n",yytext);
"}" printf("%s - Block Closing\n",yytext);
{keyword} printf("%s - keyword\n",yytext);
{id}"(".*")" printf("%s - Function\n",yytext);
{id} printf("%s - identifier\n",yytext);
{digit}* printf("%s - digit\n",yytext);
{op} printf("%s - operator\n",yytext);
"//" printf("%s - Single line comment\n",yytext);
[ \t\n;] ;
%%
main(int argc, char* argv[]) {
    FILE *fh;
    if (argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    yylex();
    return 0;
}   
