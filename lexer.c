/*
 * lexer.c - lexical analysis
 *
 */

#include <string.h>
#include <stdio.h>
#include "lexer.h"

#define SIZE 1000

char src_buf[SIZE];

char *lextext;

FILE *tokfd;

int Lex_gettok(void)
{
    while (1) {

	if (*lextext == '\0') {
	    if (fgets(src_buf, SIZE, tokfd) == NULL)
		return END_OF_FILE;
	    lextext = src_buf;
	}

	switch (*lextext) {
	case '\n':
	case '\t':
	case '\r':
	case ' ':
	    ++lextext;
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
	    ++lextext;
	    return IDENTIFIER;

	case '/':
	    ++lextext;
	    return DIVIDE;

	case '-':
	    ++lextext;
	    return MINUS;

	case '*':
	    ++lextext;
	    return MULTIPLY;

	case '(':
	    ++lextext;
	    return LEFT_PARENTHESIS;

	case '+':
	    ++lextext;
	    return PLUS;

	case ')':
	    ++lextext;
	    return RIGHT_PARENTHESIS;
	}
    }
}

void Lex_init(FILE * src)
{
    lextext = "";
    tokfd = src;
}
