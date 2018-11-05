%{
#include"code.tab.h"
%}
%%
[0-9]+ {return DIGIT;}
[a-zA-Z]+ {return LETTER;}
"+"|"/"|"*"|"-"|"=" {return OP;}
\( {return OB;}
\) {return CB;}
[ \t] ;
\n {return 0;}
. {return yytext[0];}
%%
