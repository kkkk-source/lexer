#include <stdio.h>

enum tokkind {
    END_OF_FILE,
    IDENTIFIER,
    DIVIDE,
    MINUS,
    MULTIPLY,
    LEFT_PARENTHESIS,
    PLUS,
    RIGHT_PARENTHESIS,
};


char *input_buf;

char *lextext;


int lex_next()
{
    while (1) {
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

	case '\0':
	    return END_OF_FILE;

	default:
	    fprintf(stderr, "Unexpected input found: %c\n", *lextext);
	}
    }
}


int main(void)
{
    input_buf = "1 + 2   + 3   + 4 + 5";
    lextext = input_buf;

    for (int i = 0; i < 9; i++) {
	printf("%d\n", lex_next());
    }

    return 0;
}
