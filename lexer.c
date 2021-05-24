/*
 * lexer.c - lexical analysis
 *
 */

#include <stdio.h>
#include "lexer.h"

#define BUF_SIZE 2048

// File source descriptor
FILE *tokfd;

// Lexeme text character
char *lextext;

// Buffer holding one line at a time of the source file tokfd
char buf[BUF_SIZE];

// Read the next line from the file descriptor tokfd
void repeek(void)
{
    if (fgets(buf, BUF_SIZE, tokfd) == NULL)
	// There is no more input to read from
	*lextext = EOF;
    else
	// Address lextext to the new line
	lextext = buf;
}

void Lex_init(FILE * src)
{
    lextext = "";
    tokfd = src;
    repeek();
}

// Return the enum that match the character that lextex is holding
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
	    // When the current line has been consumed, peek the folliwng one
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
	    // The current file has been completly consumed
	    return END_OF_FILE;
	}
    }
}
