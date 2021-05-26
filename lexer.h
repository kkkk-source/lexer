enum {
    END_OF_FILE,
    END_OF_LINE,

    IDENTIFIER,
    DIVIDE,
    MINUS,
    MULTIPLY,
    LEFT_PARENTHESIS,
    PLUS,
    RIGHT_PARENTHESIS,
};

void lex_init(FILE * src);
int lex_gettok(void);
