#include <stdio.h>
#include "lexer.h"

int main(void)
{
    lex_init(stdin);

    T t;

    do {
	t = lex_gettok();
	printf("%s\n", lex_toktostr(t));
    } while (t != TEndOfFile);

    fclose(stdin);
    return 0;
}
