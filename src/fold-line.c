#include <stdio.h>

#define MAXLINE 1000
#define MAX_LENGTH 80

int my_getline(char line[], int limit);
int break_line(char line[], int length, int shift);
void fold_line(char line[], int length);

int
main() {
    char line[MAXLINE];

    fold_line(line, my_getline(line, MAXLINE));
    printf("\n%s", line);

    return 0;
}

/*
 * my_getline: get line and put into line, return length
 */
int my_getline(char line[], int limit){
    int c, i;

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
break_line(char line[], int length, int shift) {
    int i;
    for (i = shift; i > 0; --i) {
        if (line[i] == ' ' || line[i] == '\t')
            break;
    }
    line[i] = '\n';

    return i;
}

void fold_line(char line[], int length) {
    int i;
    while (i < length - MAX_LENGTH) {
        i = break_line(line, length, i+MAX_LENGTH);
    }
}
