#include <stdio.h>

#define EOI        0		/*  end of input                */
#define SEMI       1		/*       ;                      */
#define PLUS       2		/*       +                      */
#define TIME       3		/*       *                      */
#define LP         4		/*       (                      */
#define RP         5		/*       )                      */
#define NUM_OR_ID  6		/* decimal number or identifier */

char *yytext = "";		/* Lexeme (not '\0' terminated) */
int yyleng = 0;			/* Lexeme length                */
int yylineno = 0;		/* Input line number            */


lex()
{
    static char input_buffer[128];
    char *current;

    current = yytext + yyleng;	/* Skip current lexeme */

    while (1) {			/* Get the next one */
	while (!*current) {
/* Get new lines, skipping any leading white space on the line,
* until a nonblank line is found.
*/

	    current = input_buffer;
	    if (!gets(input_buffer)) {
		*current = '\0';
		return EOI;
	    }

	    ++yylineno;

	    while (isspace(*current)) {
		++current;
	    }

	    for (; *current; ++current) {
/* Get next token */

		yytex = current;
		yyleng = 1;

		switch (*current) {
		case EOF:
		    return EOI;
		case ';':
		    return SEMI;
		case '+':
		    return PLUS;
		case '*':
		    return TIMES;
		case '(':
		    return LP;
		case ')':
		    return RP;

		case '\n':
		case '\t':
		case ' ':
		    break;
		default:
		    if (!isalnum(*current)) {
			fprintf(stderr, "Ignoring illegal input <%c>\n",
				*current);
		    }
		    while (isalnum(*current)) {
			++current;
		    }

		    yyleng = current - yytext;
		    return NUM_OR_ID;
		}
	    }
	}
    }
}

static int Lookahead = -1;	/* Lookahead token */

int match(int token)
{
/* Return true if "token" matches the current lookahead symbol */

    if (Lookahead == -1) {
	Lookahead = lex();
    }

    return token == Lookahead;
}

void advance()
{
/* Advance the lookahead to the next input symbol */
    Lookahead = lex();
}
