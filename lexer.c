/*
 * lexer.c - lexical analysis
 *
 */

#include <stdio.h>
#include "lexer.h"

#define BUF_SIZE 2048

// lextext holds one character at a time of buf. For now, one character
// represents a lexeme.
char *lextext;

// buf holds one line at a time of the source file srcfd.
char buf[BUF_SIZE];

// srcfd is the source file descriptor, the file to get the source code from.
FILE *srcfd;

// repeek puts the next line from the file descriptor srcfd into buf.
void repeek(void)
{
    if (fgets(buf, BUF_SIZE, srcfd) == NULL)
	// There is no more lines to read from in srcfd.
	*lextext = EOF;
    else
	// Address lextext to the first character of the new line.
	lextext = buf;
}

// Lex_init loads the first line of the src file into the buf and makes the
// lextext to point to the buf's first character.  The source file src is the
// file to get the source code from. Lex_init expects the file src to be
// already opened.
void Lex_init(FILE * src)
{
    lextext = "";
    srcfd = src;
    repeek();
}

// Lex_gettok returns the enum that match the lexeme that lextext is currently
// pointing to.
int Lex_gettok(void)
{
    for (;;) {
	switch (*lextext) {
	case '\n':
	case '\t':
	case '\r':
	case ' ':
	    lextext++;
	    break;

	case '\0':
	    // When the lextext points the '\0' character of the buf, put the
	    // following line into buf.
	    repeek();
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

	case EOF:
	    // The current source file srcfd has been completly consumed.
	    return END_OF_FILE;

	default:
	    // Unexpected character. Ignore it for now.
	    lextext++;
	}
    }
}
