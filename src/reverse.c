/* Excercise 1-19 from K&R's cpl book, */
#include <stdio.h>

#define MAXLINE 1000

int
my_getline(char line[], int lim);
void
reverse(int len, char in_line[], char out_line[]);

/* Print reversed lines for each line in input. */
int
main()
{
    int len;
    char line[MAXLINE];
    char reversed[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        reverse(len, line, reversed);
        printf("%s", reversed);
    }
    return 0;
}

/* my_getline: read a line to line, return lim */
int
my_getline(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* reverse: reverse a line from in_line and put it in put_line */
void
reverse(int len, char in_line[], char out_line[])
{
    for (int i = 0; i < len - 1; ++i)
        out_line[len - 2 - i] = in_line[i];
    out_line[len - 1] = '\n';
    out_line[len] = '\0';
}
