%{
#include"code.tab.h"
%}
%%
[0-9]+    {return DIGIT;}
[a-zA-Z]+ {return LETTER;}
\n {return 0; }
[ \t]       ;
.          {return yytext[0];}
%%

