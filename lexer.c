/*
 * lexer.c - lexical analysis
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

#define MAX_LINE_LENGTH 2048

/* The file to get the source code from. */
static FILE *source_file;

/* The input of text being scanned. */
static char input[MAX_LINE_LENGTH];

/* The current character in input. */
static char *ch;

/* The string representation of all types of tokens. */
static char *tokenstrings[] = {
    "end of file",		/* TEndOfFile        0 */
    "error",			/* TError              */
    "identifier",		/* TIdent              */
    "\"/\"",			/* TDivide             */
    "\"-\"",			/* TMinus              */
    "\"*\"",			/* TMultiply         5 */
    "\"(\"",			/* TLeftParenthesis    */
    "\"+\"",			/* TPlus               */
    "\")\"",			/* TRightParenthesis   */
};

/* lex_tok2string returns the string representation of the Type t. */
char *lex_tok2string(Type t)
{
    return tokenstrings[t];
}

/* load_line reads the next line of source_file and stores it in input. */
static void load_line(void)
{
    /* 
     * If fgets returns NULL, there is no more lines to read from. Otherwise,
     * set ch to the first character of the new line. 
     */
    ch = fgets(input, MAX_LINE_LENGTH, source_file);
}

/*
 * lex_init reads the first line of the src file and stores it in input and
 * sets the ch to the input's first character.  The source file src is the file
 * to get the source code from. lex_init expects the file src to be already
 * opened.
 */
void lex_init(FILE * src)
{
    source_file = src;
    load_line();
}

/* 
 * lex_next returns the enum that match the lexeme that ch is currently
 * pointing to. The max lexeme width is just one character.
 */
struct Token *lex_next(void)
{
    while (ch != NULL) {

	struct Token *tok = malloc(sizeof(struct Token));
	tok->text = *ch;

	switch (*ch) {

	case '\0':
	    /* 
	     * When the ch is the '\0' character of the line, load the following
	     * line. 
	     */
	    load_line();
	    break;

	case '\n':
	case '\t':
	case '\r':
	case ' ':
	    ch++;
	    break;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	    ch++;
	    tok->type = TIdent;
	    return tok;

	case '/':
	    ch++;
	    tok->type = TDivide;
	    return tok;

	case '-':
	    ch++;
	    tok->type = TMinus;
	    return tok;

	case '*':
	    ch++;
	    tok->type = TMultiply;
	    return tok;

	case '(':
	    ch++;
	    tok->type = TLeftParenthesis;
	    return tok;

	case '+':
	    ch++;
	    tok->type = TPlus;
	    return tok;

	case ')':
	    ch++;
	    tok->type = TRightParenthesis;
	    return tok;

	default:
	    ch++;
	    tok->type = TError;
	    return tok;
	}
    }

    /* The current source file source_file has been completly consumed. */
    struct Token *tok = malloc(sizeof(struct Token));
    tok->type = TEndOfFile;
    tok->text = EOF;
    return tok;
}
