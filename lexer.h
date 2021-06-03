/* Type represents a token type */
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
} type;

struct token {
    type type;
    char text; /* the lexeme is only a `char` long. */
};

/*
 * lex_init reads the first line of the src file and stores it in input and
 * sets the ch to the input's first character.  The source file src is the file
 * to get the source code from. lex_init expects the file src to be already
 * opened.
 */
void lex_init(FILE * src);

/* lex_next find the next token in the input and stores it into tok. */
void lex_next(struct token * tok);

/* lex_tok2string returns the string representation of the Type t. */
char *lex_tok2string(type t);
