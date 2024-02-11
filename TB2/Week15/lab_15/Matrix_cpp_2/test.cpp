#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <iostream>
#include <cstdlib>

bool isInt(double x)
{
    return (x == int(x)); 
}

int main()
{
    double x = 1;
    double y = 0.5;

    if (isInt(x))
    {
        printf("%f is an int\n", x);
    }

    if (isInt(y))
    {
        printf("%f is an int\n", y);
    }
    return 0;
}