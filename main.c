#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

int main(void)
{
    lex_init(stdin);

    struct token *tok = malloc(sizeof(struct token));

    do {
	lex_next(tok);
	printf("type: %s text: %c\n", lex_tok2string(tok->type),
	       tok->text);
    } while (tok->type != TEndOfFile);

    free(tok);
    fclose(stdin);
    return 0;
}
