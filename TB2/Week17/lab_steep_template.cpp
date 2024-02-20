#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Problem
{
    double epsilon;
    double x0; // initial point
    
    virtual double f(double x)
    {
        return sin(x / 2) + cos(x / 4);
    }

    virtual double df(double x)
    {
        return cos(x / 2) / 2 - sin(x / 4) / 4;
    }

    // solve the subproblem
    // argmin_x\in [xt-epsilon, xt+epsilon] f(x)
    double subproblem(double xt)
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

public:
    Problem(double eps, double initial_guess)
    {
        epsilon = eps;
        x0 = initial_guess;
    }

    void set_epsilon(double eps)
    {
        epsilon = eps;
    }

    void set_x0(double initial_guess){
        x0 = initial_guess;
    }


    // solve the problem using hill-climbing
    void solve()
    {
        double xt = x0;
        double xt_1 = __DBL_MAX__; // initialise xt-1 to be far away from xt
        while( fabs(xt - xt_1) >= 1e-5){ // fabs absolute value function
            xt_1 = xt; 
            xt = subproblem(xt);
            printf("f(%.4f) = %.4f\n", xt, f(xt));
        }

        printf("Maximum is at %f with value %f\n", xt, f(xt));
    }

    void GAsolve(int maxIterations)
    {
        double xt = x0;
        // This loop will probably not run maxIterations times as the stopping
        // thereshold is likely to be met before that.
        for(int i = 0; i < maxIterations; i++)
        {
            // gradient ascent!
            double xt1 = xt + epsilon*df(xt);
            // do we stop?
            if (fabs(xt1 - xt) < 1e-5)
            {
                xt = xt1;
                break; 
            }
            xt = xt1;
            printf("f(%f) = %f\n", xt, f(xt));
        }
        printf("Maximum is at %f with value %f\n", xt, f(xt));
    }

};

class NewProblem: public Problem
{
    double f(double x)
    {
        return -x*x;
    }

    double df(double x)
    {
        return -2*x;
    }

    public:
        NewProblem(double eps, double initialGuess) : Problem(eps, initialGuess){}
};

int main()
{   
    // Solve problem with hill-climbing
    Problem p(0.5, -4);
    printf("hill climbing... \n");
    p.solve();
    printf("------------------------\n");

    // TODO your gradient ascent code
    printf("Gradiient ascent... \n");
    p.GAsolve(1000);
    printf("------------------------\n");

    NewProblem p2(0.5, -4);

    printf("New Problem hill climbing... \n");
    p2.solve();
    printf("------------------------\n");

    printf("New Problem Gradient Ascent... \n");
    p2.GAsolve(1000);
}
