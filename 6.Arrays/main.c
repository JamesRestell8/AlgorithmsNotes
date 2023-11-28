#include <stdio.h>
#include <stdlib.h>

// get the dot product of two vectors
double dotProduct(double x[], double y[], int length)
{
    double answer = 0;
    for (int i = 0; i < length; i++)
    {
        answer += x[i] * y[i];
    }
    return answer;
}

void addOne(int x[], int y[], int length)
{
    for (int i = 0; i < length; i++)
    {
        y[i] = x[i] + 1;
    }
}

int main()
{
    // defines an array with size 100
    int array[100]; 
    // Note that the size of an array cannot be a variable

    // arrays can also be defined as follows
    int array2[] = {1,2,3,4,5,6,7,8,9};
    return 0;

    // adding vectors by accessing elements:
    double v1[] = {0.5, 1.0, -0.25};
    double v2[] = {1, -2.0, 0.75};
    double added[3];

    for (int i = 0; i < 3; i++)
    {
        added[i] = v1[i] + v2[i];
    }

    // variables such as integers are passed to functions by value, which means modifications
    // made to that variable in the function are not global.

    // however, when you pass an array to a function, it is passed by reference, which means
    // changes made in the function are reflected globally

    // also note that functions CANNOT return arrays. However, you can pass in an array as an input
    // which can be modified in the array and accessed in the main function.

    // for example, here we call a function that adds one to all elements in a and assigns it to an array b

    int a[] = {1, 2, 3};
    int b[3];
    addOne(a, b, 3);
    // b now equals {2, 3, 4}
    // a still equals {1, 2, 3}
}