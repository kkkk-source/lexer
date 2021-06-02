/* Type indentify a token type */
typedef enum {
    TEndOfFile,
    TError,
    TIdent,
    TDivide,
    TMinus,
    TMultiply,
    TLeftParenthesis,
    TPlus,
    TRightParenthesis,
} Type;

/*
 * lex_init loads the first line of the src file into the buf and makes the
 * lextext to point to the buf's first character.  The source file src is the
 * file to get the source code from. lex_init expects the file src to be
 * already opened.
 */
void lex_init(FILE * src);

/* 
 * lex_next returns the token type (enum) that match the lexeme that lextext
 * is currently pointing to. 
 */
Type lex_next(void);

/* lex_toktostr returns the string representation of T. */
char *lex_tok2string(Type);
