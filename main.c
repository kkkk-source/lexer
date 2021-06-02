#include <stdio.h>
#include "lexer.h"

int main(void)
{
    lex_init(stdin);

    Type t;

    do {
	t = lex_next();
	printf("%s\n", lex_tok2string(t));
    } while (t != TEndOfFile);

    fclose(stdin);
    return 0;
}
