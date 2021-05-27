/*
 * lexer.c - lexical analysis
 *
 */

#include <stdio.h>
#include "lexer.h"

#define MAX_LINE_LENGTH 2048

/* buf holds one line at a time of the source file srcfd. */
char buf[MAX_LINE_LENGTH];

/* lextext holds one character at a time of buf. */
char *lextext;

/* srcfd is the source file descriptor, the file to get the source code from. */
FILE *srcfd;

char *tokstrings[] = {
    "EOF",			/* END_OF_FILE       0 */
    "EOL",			/* END_OF_LINE         */
    "ID",			/* IDENTIFIER          */
    "/",			/* DIVIDE              */
    "-",			/* MINUS               */
    "*",			/* MULTIPLY          5 */
    "(",			/* LEFT_PARENTHESIS    */
    "+",			/* PLUS                */
    ")",			/* RIGHT_PARENTHESIS   */
};

/* peek puts the next line from the file descriptor srcfd into buf. */
void peek(void)
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
 * file to get the source code from. Lex_init expects the file src to be
 * already opened.
 */
void lex_init(FILE * src)
{
    lextext = "";
    srcfd = src;
    peek();
}

/* 
 * lex_gettok returns the enum that match the lexeme that lextext is currently
 * pointing to. 
 */
int lex_gettok(void)
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
	    peek();
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
	    return IDENTIFIER;

	case '/':
	    lextext++;
	    return DIVIDE;

	case '-':
	    lextext++;
	    return MINUS;

	case '*':
	    lextext++;
	    return MULTIPLY;

	case '(':
	    lextext++;
	    return LEFT_PARENTHESIS;

	case '+':
	    lextext++;
	    return PLUS;

	case ')':
	    lextext++;
	    return RIGHT_PARENTHESIS;

	default:
	    /* Unexpected character. Ignore it for now. */
	    lextext++;
	}
    }

    /* The current source file srcfd has been completly consumed. */
    return END_OF_FILE;
}
