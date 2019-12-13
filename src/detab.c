/* Exercise 1-20 from K%R's cpl book. */
#include <stdio.h>

#define MAXLINE 1000

int
my_getline(char line[], int lim);
void
detab(char line[], int len, int num);
int
rshift(char line[], int len, int pos, int shift);

/* Get lines and return lines with tabs replaced by spaces. */
int
main()
{
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        detab(line, len, 4);
        printf("%s", line);
    }
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

/* shift: shift chars in line by shift */
int
rshift(char line[], int len, int pos, int shift)
{
    if (shift < 0 || len + shift > MAXLINE)
        return -1;
    for (int i = len; i >= pos; --i)
        line[i + shift] = line[i];
    return len + shift;
}

/* detab: replace tabs with spaces in line */
void
detab(char line[], int len, int num)
{
    int i = 0;
    int shift = num - 1;

    while (i < len) {
        if (line[i] == '\t') {
            len = rshift(line, len, i, shift);
            int ishift = i + shift;
            while (i < ishift)
                line[i++] = ' ';
            line[i] = ' ';
        }
        ++i;
    }
}
