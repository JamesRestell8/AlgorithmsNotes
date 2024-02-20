#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Using Gradient Ascent as opposed to Hill Climbing from last week
// This is still myopic but is computationally quicker.

// the derivative of f(x) = x^3 + x^2
double df(double x)
{
    return 3 * (pow(x, 2)) + 2*x;
}

int main()
{
    double x0 = -2; //initial guess
    double dfx0 = df(x0);
    int T = 1000; //maximum iteration
    double epsilon = 0.1; // step size
    double eta = 1e-5; // stopping threshold
    double xt = x0;
    double dfxt = dfx0;
    for(int t=0; t<T; t++){
        // gradient ascent!
        double xt1 = xt + epsilon*dfxt;
        double dfxt1 = df(xt1);
        // do we stop?
        if (fabs(dfxt1 - dfxt) < eta){
            xt = xt1;
            dfxt = dfxt1;
            break;
        }
        xt = xt1;
        dfxt = dfxt1;
    }
    printf("%f\n", xt);
    return 0;
}