/*
 * lexer.c - lexical analysis
 *
 */

#include <stdio.h>
#include "lexer.h"

#define MAX_LINE_LENGTH 2048

/* buf holds one line at a time of the source file srcfd. */
static char buf[MAX_LINE_LENGTH];

/* lextext holds one character at a time of buf. */
static char *lextext;

/* srcfd is the source file descriptor, the file to get the source code from. */
static FILE *srcfd;

static char *tokstrings[] = {
    "end of file",		/* TEndOfFile        0 */
    "identifier",		/* TIdent              */
    "\"/\"",			/* TDivide             */
    "\"-\"",			/* TMinus              */
    "\"*\"",			/* TMultiply         5 */
    "\"(\"",			/* TLeftParenthesis    */
    "\"+\"",			/* TPlus               */
    "\")\"",			/* TRightParenthesis   */
};

char *lex_toktostr(Type t)
{
    return tokstrings[t];
}

/* load_line puts the next line from the file descriptor srcfd into buf. */
static void load_line(void)
{
    /* 
     * If fgets returns NULL, there is no more lines to read from. Otherwise,
     * points lextext at the first character of the new line. 
     */
    lextext = fgets(buf, MAX_LINE_LENGTH, srcfd);
}

/*
 * lex_init loads the first line of the src file into the buf and makes the
 * lextext to point to the buf's first character.  The source file src is the
 * file to get the source code from. lex_init expects the file src to be
 * already opened.
 */
void lex_init(FILE * src)
{
    lextext = "";
    srcfd = src;
    load_line();
}

/* 
 * lex_next returns the enum that match the lexeme that lextext is currently
 * pointing to. 
 */
Type lex_next(void)
{
    /* Loop while lextext is not equals to NULL. */
    while (lextext) {

	switch (*lextext) {
	case '\n':
	case '\t':
	case '\r':
	case ' ':
	    lextext++;
	    break;

	case '\0':
	    /* 
	     * When the lextext points the '\0' character of the buf, put the
	     * following line into buf. 
	     */
	    load_line();
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
	    lextext++;
	    return TIdent;

	case '/':
	    lextext++;
	    return TDivide;

	case '-':
	    lextext++;
	    return TMinus;

	case '*':
	    lextext++;
	    return TMultiply;

	case '(':
	    lextext++;
	    return TLeftParenthesis;

	case '+':
	    lextext++;
	    return TPlus;

	case ')':
	    lextext++;
	    return TRightParenthesis;

	default:
	    /* Unexpected character. Ignore it for now. */
	    lextext++;
	}
    }

    /* The current source file srcfd has been completly consumed. */
    return TEndOfFile;
}
