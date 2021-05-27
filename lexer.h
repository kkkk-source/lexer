/* token types */
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

/*
 * lex_init loads the first line of the src file into the buf and makes the
 * lextext to point to the buf's first character.  The source file src is the
 * file to get the source code from. Lex_init expects the file src to be
 * already opened.
 */
void lex_init(FILE * src);

/* 
 * lex_gettok returns the token type (enum) that match the lexeme that lextext
 * is currently pointing to. 
 */
int lex_gettok(void);
