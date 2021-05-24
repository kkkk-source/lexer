enum {
  END_OF_FILE,
  END_OF_INPUT,
  IDENTIFIER,
  DIVIDE,
  MINUS,
  MULTIPLY,
  LEFT_PARENTHESIS,
  PLUS,
  RIGHT_PARENTHESIS,
};

void Lex_init(FILE * src);
int Lex_gettok(void);
