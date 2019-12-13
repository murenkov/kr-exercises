/* Exercise 1-18 from K&R's cpl book. */
#include <stdio.h>

#define MAXLINE 1000

int
my_getline(char line[], int lim);
void
rm_trailing_blanks(char line[], int len);

/* Remove blank lines and trailing blanks from input and print. */
int
main()
{
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > 2) {
            rm_trailing_blanks(line, len);
            printf("%s", line);
        }
    }
    return 0;
}

/* my_getline: read a line into line, return length. */
int
my_getline(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c = '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* rm_trailing_blanks: remove trailing spaces and tabs. */
void
rm_trailing_blanks(char line[], int len)
{
    int i = len - 2;

    while (line[i] == ' ' || line[i] == '\t') {
        --i;
    }
    if (line[len - 1] = '\n')
        line[++i] = '\n';
    line[++i] = '\0';
}
