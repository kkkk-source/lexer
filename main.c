#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

int main(void)
{
    lex_init(stdin);

    struct Token *tok;

    do {
	tok = lex_next();
	printf("type: %s text: %c\n", lex_tok2string(tok->type),
	       tok->text);
    } while (tok->type != TEndOfFile);

    free(tok);
    fclose(stdin);
    return 0;
}
