#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 100
#define IN 1
#define OUT 0

int _readline(char *line, int limit);
bool parentheses_balanced(char *line, int length);
bool brackets_balanced(char *line, int length);
bool braces_balanced(char *line, int length);

int
main() {
    char line[MAXLINE];

    int length = _readline(line, MAXLINE);
    printf("Parentheses are balanced: %d\n", parentheses_balanced(line, length));
    printf("Brackets are balanced: %d\n", brackets_balanced(line, length));
    printf("Braces are balanced: %d\n", braces_balanced(line, length));

    return 0;
}


int
_readline(char *line, int limit) {
    /**
     * Read a line and return its length.
     */
    char c;
    int i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

bool
parentheses_balanced(char *line, int length) {
    int counter = 0;
    int state = OUT;

    for (int i = 0; i < length; ++i) {
        // printf("counter = %d\n", counter);
        if (state == OUT) {
            if (line[i] == '(')
                ++counter;
            if (line[i] == ')')
                --counter;
        }
    }

    return counter == 0;
}

bool
brackets_balanced(char *line, int length) {
    int counter = 0;
    int state = OUT;

    for (int i = 0; i < length; ++i) {
        if (state == OUT) {
            if (line[i] == '[')
                ++counter;
            if (line[i] == ']')
                --counter;
        }
    }

    return counter == 0;
}

bool
braces_balanced(char *line, int length) {
    int counter = 0;
    int state = OUT;

    for (int i = 0; i < length; ++i) {
        if (state == OUT) {
            if (line[i] == '{')
                ++counter;
            if (line[i] == '}')
                --counter;
        }
    }

    return counter == 0;
}
