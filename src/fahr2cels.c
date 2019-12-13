#include <stdio.h>

/* convert Fahrenheit to Celsius */
double
fahr2cels(double fahr)
{
    return 5.0 / 9.0 * (fahr - 32.0);
}

double
cels2fahr(double cels)
{
    return 0;
}

int
main()
{
    for (int i = 0; i <= 300; i += 20)
        printf("%3d %6.1f\n", i, fahr2cels(i));
}
