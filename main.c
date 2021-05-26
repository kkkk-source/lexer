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

    fclose(stdin);
    return 0;
}
