#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

class Matrix{
    //TODO: Write a matrix class with three private fields: 
    //  num_rows: integer, stores the number of rows 
    //  num_cols: integer, stores the number of columns
    //  elements: integer pointer, pointing to a contiguous memory stores a row-major matrix.
    int num_rows, num_cols;
    int *elements;

// all functions below must be PUBLIC!
    public:
//TODO: Write set_elem and get get_elem functions. Must check for invalid indices.
// Use zero-based indexing!
    void set_elem(int i, int j, int val)
    {
        if ((0 <= i) && (i <= num_rows - 1) && (0 <= j) && (j <= num_cols - 1))
        {
            elements[i * num_cols + j] = val;
        } else
        {
            printf("Invalid indices\n");
        }
    }

    int get_elem(int i, int j)
    {
        if ((0 <= i) && (i <= num_rows - 1) && (0 <= j) && (j <= num_cols - 1))
        {
            return elements[i * num_cols + j];
        }
        else
        {
            printf("Invalid indices\n");
            return -1;
        }
    }
//TODO: Write a print function.
    void print()
    {
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                printf("%d ", get_elem(i, j));
            }
            printf("\n");
        }
        printf("\n");
    }
//TODO: Write an add function. Must check for invalid dimensions.
    void add(Matrix B)
    {
        if ((num_cols == B.num_cols) && (num_rows == B.num_rows))
        {
            for (int i = 0; i < num_rows; i++)
            {
                for (int j = 0; j < num_cols; j++)
                {
                    set_elem(i, j, B.get_elem(i, j) + get_elem(i, j));
                }
            }
        } else
        {
            printf("Incompatible dimensions.\n");
        }
    }
//TODO: Write a constructor, which takes three arguments: nrow, ncol, and elem.
// Must check nrow and ncol are positive integers. If they are not, print "invalid dimensions!" and do nothing.
    Matrix(int nrow, int ncol, int* elems)
    {
        if ((nrow > 0) && (ncol > 0))
        {
            num_rows = nrow; 
            num_cols = ncol;
            elements = elems;
        } else
        {
            printf("Invalid dimensions!");
        }
    }
};

int main(){
    //testing code for the matrix class.

    // prepare data in the stack memory. In this lab, DO NOT USE HEAP MEMORY.
    int num_rows = 2;
    int num_cols = 3;

    int elementsA[] = {1, 2, 3, 4, 5, 6};
    int elementsB[] = {7, 8, 9, 10, 11, 12};

    // TODO: After you finished writing your matrix class, uncomment the following code and test your matrix class.

    // create two matrices, with constructor.
    Matrix A(num_rows, num_cols, elementsA);
    Matrix B(num_rows, num_cols, elementsB);

    // test your setter and getter functions.
    A.set_elem(0, 0, 9);
    A.print();

    // using the setter function but with invalid indices.
    B.set_elem(2, -2, 100);
    B.print();


    // write your own code and test your add function:
    A.add(B);
    A.print();

    // write your own code and test your add function but with incompatible dimensions:
    // Hint: you can create a new matrix C which is 3 by 2, and test your add function.
    Matrix C(num_cols, num_rows, elementsA);
    A.add(C);
}