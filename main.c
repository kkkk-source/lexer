#include <stdio.h>
#include "lexer.h"

int main(void)
{
    lex_init(stdin);

    int tok;

    do {
	tok = lex_gettok();
	printf("%d\n", tok);
    } while (tok != END_OF_FILE);

    return 0;
}
