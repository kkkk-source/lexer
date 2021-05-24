#define END_OF_FILE 0
#define IDENTIFIER  1
#define DIVIDE 2
#define MINUS 3
#define MULTIPLY 4
#define LEFT_PARENTHESIS 5
#define PLUS 6
#define RIGHT_PARENTHESIS 7

void Lex_init(FILE * src);
int Lex_gettok(void);
