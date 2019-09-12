/* Exercise 1.9 from K&R's cpl book.
Program copies chars from input and puts them into output wremoving extra spaces
*/

#include  <stdio.h>

main()
{
    int ch, prev_ch = 0;
    
    while ((ch = getchar()) != EOF) {
        if (prev_ch == ' ' && ch == ' ') continue;
        putchar(ch);
        prev_ch = ch;
    }
}
