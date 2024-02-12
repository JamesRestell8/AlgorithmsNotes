#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This is the function we want to maximise, you 
// can experiment with differenf function if you want.
double f(double x){
    return sin(x/2) + cos(x/4);
}

// This function returns xmax that maximizes f(x)
// between x-epsilon and x+epsilon
// complete the code yourself
double subproblem(double xt, double epsilon){
    double x = xt - epsilon;
    double fmax = -100; // Sloppy!
    double xmax = x;
    while(x <= xt + epsilon){
        //fill out the if statement
        //if(_____){
        //  
        //}
        x += epsilon/100;
    }
    return xmax;
}

int main(){
    double epsilon = .5;
    double x0 = -4; //initial point
    
    double xt = x0; 
    double xt_1 = 100; // xt-1
    
    while( fabs(xt - xt_1) >= 1e-5){ // fabs absolute value function
        xt_1 = xt; 
        // _________ // fill out the blank
        printf("f(%.4f) = %.4f\n", xt, f(xt));
    }

    printf("Maximum is at %f with value %f\n", xt, f(xt));
}
