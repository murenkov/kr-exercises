/* Exercise 1-21 from K&R's cpl book. */
#include <stdio.h>

#define MAXLINE 1000

int
my_getline(char line[], int lim);
int
lshift(char line[], int len, int pos, int shift);
void
entab(char line[], int len, int tabstop);

/* Replace multiple spaces with tabs */
int
main()
{
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        entab(line, len, 4);
        printf("%s", line);
    }
    return 0;
}

/* my_getline: get line and put into line, return length */
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

/* lshift: shift line left by shift chars from pos position */
int
lshift(char line[], int len, int pos, int shift)
{
    int i;

    if (shift < 0 || pos - shift < 0)
        return -1;
    for (i = pos; i <= len; ++i)
        line[pos - shift] = line[pos];
    return len - shift;
}

/* entab: replace every num spaces with tab */
void
entab(char line[], int len, int tabstop)
{
    int i = 0;
    int space_counter = 0;

    while (i < len) {
        if (line[i] == ' ')
            ++space_counter;
        if (space_counter = tabstop)
            ;
    }
}
