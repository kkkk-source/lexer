#include <stdio.h>
#include "lexer.h"

int main(void)
{
  Lex_init(stdin);

  int tokkind;

  do {
    tokkind = Lex_gettok();
    printf("%d\n", tokkind);
  } while (tokkind != END_OF_FILE);

  return 0;
}
