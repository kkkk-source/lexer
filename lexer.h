/* T indentify a token type */
typedef enum {
    TEndOfFile,
    TIdent,
    TDivide,
    TMinus,
    TMultiply,
    TLeftParenthesis,
    TPlus,
    TRightParenthesis,
} T;

/*
 * lex_init loads the first line of the src file into the buf and makes the
 * lextext to point to the buf's first character.  The source file src is the
 * file to get the source code from. lex_init expects the file src to be
 * already opened.
 */
void lex_init(FILE * src);

/* 
 * lex_gettok returns the token type (enum) that match the lexeme that lextext
 * is currently pointing to. 
 */
T lex_gettok(void);

/* lex_toktostr returns the string representation of T. */
char *lex_toktostr(T);
