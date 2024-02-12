#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <cmath>

/* 
    SEARCH ALGORITHMS 
    Not just finding numbers but also encryption keys, optimal chess moves etc.
*/

double f(double x)
{
    return -pow(x, 2); // Change this to find different max
}

// THIS FUNCTION ONLY FINDS LOCAL MAXIMUMS IN THE INTERVAL [xt-epsilon, xt+epsilon]
// Making epsilon larger gives you a better chance of finding the global maximum, but it takes more computation.
double subproblem(double xt, double epsilon)
{
    double x = xt - epsilon;
    double fmax = -__DBL_MAX__;
    double xmax = x;
    while (x <= xt + epsilon)
    {
        if (f(x) > fmax)
        {
            xmax = x;
            fmax = f(x);
        }
        x += epsilon / 100;
    }
    return xmax;
}

int main()
{
    double epsilon = 0.5;
    double x0 = -2; // Initial guess

    double xt = x0;
    double xt_1 = -10; // x_{t-1} previous iteration

    while (fabs(xt - xt_1) >= 1e-5)
    {
        xt_1 = xt;
        xt = subproblem(xt, epsilon);
        printf("f(%.4f) = %.4f\n", xt, f(xt));
    }
    printf("Maximum is at %f with value %f\n", xt, f(xt));
    return 0;
}