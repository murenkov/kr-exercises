#include <stdio.h>

#define MAXLINE 1000
#define IN 1
#define OUT 0

int _readline(char *line, int limit);
int remove_oneline_comment(char *text, int length);

int
main() {
    char text[MAXLINE];

    int length = remove_oneline_comment(text, _readline(text, MAXLINE));
    printf("%s\n", text);

    return 0;
}

int
_readline(char *line, int limit) {
    /**
     * _readline:
     * Read a line. Return its length.
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

int
remove_oneline_comment(char *text, int length) {
    /**
     * remove_comments:
     * Remove oneline comments.
     */

    int comment_start;
    int state = OUT;
    int i;

    for (i = 0; i < length - 1; ++i) {
        if (text[i] == '"')
            state = (state == OUT) ? IN : OUT;

        if (state == OUT)
            if (text[i] == '/' && text[i+1] == '/') {
                text[i] = '\0';
                break;
            }
    }

    return i;
}
