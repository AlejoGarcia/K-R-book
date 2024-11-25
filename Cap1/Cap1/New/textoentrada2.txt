#include <stdio.h>

#define MAXLINE 1000	/* max line length acceptable */

#define STATEINIT	0 	/* initial state */
#define STATELIT1	1 	/* inside literal type 1 */
#define STATELIT2	2 	/* inside literal type 2 */
#define STATECOM1	3	/* inside a commment type 1 */
#define STATECOM2	4	/* inside a commment type 2 */

#define PARENTHESIS	0	/* signs (, ) */
#define CURLYBRACES	1	/* signs {, } */
#define BRACKETS	2	/* signs [, ] */
#define SINGLEQUOTE	3	/* sign ' */
#define DOUBLEQUOTE	4	/* sign " */
#define COMMENTS	5	/* sign comment */

char stack[MAXLINE];
int sp = 0;

char push(char val);
int pop(void);

/* Checks for bracket and other signs parity and correction */
main()
{
	char c;			/* current char */
	char p;			/* prev char */
	char state;		/* current state */
	char aux;		/* aux var */
	char nl;		/* line counter */
	char r;			/* result var */

	r = 0;
	nl = 1;
	p = '\0';
	state = STATEINIT;
	while (r == 0 && (c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (state == STATEINIT) {
			if (c == '\'' && p != '\\') {
				push(SINGLEQUOTE);
				state = STATELIT1;
			} else if (c == '\"' && p != '\\') {
				push(DOUBLEQUOTE);
				state = STATELIT2;
			} else if (c == '*' && p == '/') {
				push(COMMENTS);
				state = STATECOM1;
			} else if (c == '/' && p == '/') {
				push(COMMENTS);
				state = STATECOM2;
			} else if (c == '(') {
				push(PARENTHESIS);
			} else if (c == '{') {
				push(CURLYBRACES);
			} else if (c == '[') {
				push(BRACKETS);
			} else if (c == ')') {
				if (pop() != PARENTHESIS) {
					r = -1;
				}
			} else if (c == '}') {
				if (pop() != CURLYBRACES) {
					r = -1;
				}
			} else if (c == ']') {
				if (pop() != BRACKETS) {
					r = -1;
				}
			}
		} else if (state == STATELIT1) {
			if (c == '\'' && p != '\\') {
				if (pop() != SINGLEQUOTE) {
					r = -1;
				}
				state = STATEINIT;
			}
		} else if (state == STATELIT2) {
			if (c == '\"' && p != '\\') {
				if (pop() != DOUBLEQUOTE) {
					r = -1;
				}
				state = STATEINIT;
			}
		} else if (state == STATECOM1) {
			if (c == '/' && p == '*') {
				if (pop() != COMMENTS) {
					r = -1;
				}
				state = STATEINIT;
			}
		} else if (state == STATECOM2) {
			if (c == '\n') {
				if (pop() != COMMENTS) {
					r = -1;
				}
				state = STATEINIT;
			}
		} 
		p = c;
	}
	
	if (r < 0)
		printf("Syntactic error. Unbalanced sign '%c'. In line %d.\n", c, nl);
	else
		printf("Analysis completed: No errors found.\n");
	return 0; 
}

void printstack(void)
{
	int i;
	if (sp == 0)
		printf("[]\n");
	else {
		printf("[%d", stack[0]);	
		for (i = 1; i < sp; ++i)
			printf(", %d", stack[i]);
		printf("]\n");
	}
}

/* Pushes a value (char v) on to the stack */
char push(char v)
{
	char r = -1;
	if (sp < MAXLINE) {
		stack[sp] = v;
		++sp;
		r = 0;
	}
	return r;
}

/* Pops a value (char) from the stack */
int pop(void)
{
	int r = -1;
	if (sp > 0) {
		--sp;
		r = stack[sp];
	}
	return r;
}
