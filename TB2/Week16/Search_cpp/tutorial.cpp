#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <utility>

class matrix
{
    //   num_rows: integer, stores the number of rows
    //   num_cols: integer, stores the number of columns
    //   elements: integer pointer, pointing to a contiguous memory stores a row-major matrix.

    int num_rows;
    int num_cols;
    int *elements;

    // all functions below must be PUBLIC!
public:

    int get_num_rows() { return num_rows; }
    int get_num_cols() { return num_cols; }

    void set_elem(int i, int j, int value)
    {
        if (i < 0 || i >= num_rows || j < 0 || j >= num_cols)
        {
            printf("invalid indices!\n");
        }
        else
        {
            elements[i * num_cols + j] = value;
        }
    }

    int get_elem(int i, int j)
    {
        if (i < 0 || i >= num_rows || j < 0 || j >= num_cols)
        {
            printf("invalid indices!\n");
            return 'N';
        }
        else
        {
            return elements[i * num_cols + j];
        }
    }

    matrix(int nrow, int ncol)
    {
        if (nrow <= 0 || ncol <= 0)
        {
            printf("invalid dimensions!\n");
        }
        else
        {
            num_rows = nrow;
            num_cols = ncol;
            // printf("allocating memory for the matrix...\n");
            elements = (int *)malloc(num_rows * num_cols * sizeof(int));
        }
    }

    ~matrix()
    {
        // printf("freeing the matrix...\n");
        free(elements);
    }

    // print all elements in the matrix
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
    }

};

class Symmatrix : public matrix
{
    public:
        Symmatrix(int nrow) : matrix(nrow, nrow)
        {

        }

        void set_elem(int i, int j, int val)
        {
            if (i < 0 || i >= get_num_rows() || j < 0 || j >= get_num_cols())
            {
                printf("invalid indices!\n");
            }
            else
            {
                if (i == j)
                {
                    set_elem(i, j, val);
                } else
                {
                    set_elem(i, j, val);
                    set_elem(j, i, val);
                }
            }
        }
};

int main()
{
    Symmatrix sym(5);
    sym.print();
    sym.set_elem(1, 1, 5);
    sym.print();
    sym.set_elem(2, 4, 9);
    sym.print();
    return 0;
}