#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
• A_i,j = 1 if paper i cites j.
• A_i,j = 0 if paper i does not cite j.
• A_i,i = 0 as self-citations do not exist.
*/

class Matrix
{
    //   num_rows: integer, stores the number of rows
    //   num_cols: integer, stores the number of columns
    //   elements: integer pointer, pointing to a contiguous memory stores a row-major matrix.

    int num_rows;
    int num_cols;
    double *elements;

public:

    int get_num_rows() { return num_rows; }
    int get_num_cols() { return num_cols; }

    void set_elem(int i, int j, double value)
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

    double get_elem(int i, int j)
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

    Matrix(int nrow, int ncol)
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
            elements = (double *)malloc(num_rows * num_cols * sizeof(double));
            for (int i = 0; i < num_rows * num_cols; i++)
            {
                elements[i] = 0.0;
            }
        }
    }
    // Default constructor
    Matrix()
    {

    }

    // Deconstructor
    ~Matrix()
    {
        // printf("freeing the matrix...\n");
        elements = NULL;
        free(elements);
    }

    // print all elements in the matrix
    void print()
    {
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                printf("%f ", get_elem(i, j));
            }
            printf("\n");
        }
    }

};

class Algorithm
{
    int M;
    double epsilon;
    Matrix alpha;
    Matrix beta;
    Matrix A;

    // Normalises a vector by dividing all elements by the Euclidean norm.
    void normalise(Matrix X)
    {
        double norm = 0;
        for (int i = 0; i < X.get_num_rows(); i++)
        {
            norm += pow(X.get_elem(i, 0), 2);
        }
        norm = sqrt(norm);
        for (int i = 0; i < X.get_num_rows(); i++)
        {
            X.set_elem(i, 0, X.get_elem(i, 0) / norm);
        }
    }

public:
    Algorithm(int numIterations, double eps, Matrix a, Matrix b, Matrix X)
    {
        M = numIterations;
        epsilon = eps;
        alpha = a;
        beta = b;
        A = X;
    }

    void run()
    {
        for (int m = 0; m < M; m++)
        {
            // Step 1: Copy alpha to alphaOld.
            Matrix alphaOld(alpha.get_num_rows(), alpha.get_num_cols());
            Matrix betaOld(beta.get_num_rows(), beta.get_num_cols());

            for (int i = 0; i < alpha.get_num_rows(); i++)
            {
                alphaOld.set_elem(i, 0, alpha.get_elem(i,0));
                betaOld.set_elem(i, 0, beta.get_elem(i,0));
            }

            // Step 2, 3: Update alpha, beta
            for (int i = 0; i < 7; i++)
            {
                double alpha_i = 0;
                double beta_i = 0;
                for (int j = 0; j < 7; j++)
                {
                    alpha_i += A.get_elem(j, i) * betaOld.get_elem(j, 0);
                    beta_i += A.get_elem(i, j) * alphaOld.get_elem(j, 0);
                }
                alpha.set_elem(i, 0, alpha_i);
                beta.set_elem(i, 0, beta_i);
            }

            // Step 4: Normalise alpha and beta
            normalise(alpha);
            normalise(beta);

            // Step 5: Find max distance between alpha/beta and alphaOld/betaOld and compare to epsilon
            double maxAlph = 0;
            double maxBeta = 0;

            for (int i = 0; i < 7; i++)
            {
                double alphaNum = abs(alpha.get_elem(i, 0) - alphaOld.get_elem(i, 0));
                double betaNum = abs(beta.get_elem(i, 0) - betaOld.get_elem(i, 0));
                if (alphaNum > maxAlph)
                {
                    maxAlph = alphaNum;
                }
                if (betaNum > maxBeta)
                {
                    maxBeta = betaNum;
                }
            }

            if ((maxAlph < epsilon) && (maxBeta < epsilon))
            {
                printf("Converged after %d iterations.\n", m);
                for (int i = 0; i < 7; i++)
                {
                    printf("Impact Score of page %d is: %f, Knowledge Score: %f\n", i+1, alpha.get_elem(i, 0), beta.get_elem(i, 0));
                }
                return;
            }
        }
        // If not converged after M iterations, print results.
        for (int i = 0; i < 7; i++)
        {
            printf("Impact Score of page %d is: %f, Knowledge Score: %f\n", i, alpha.get_elem(i, 0), beta.get_elem(i, 0));
        }
    }
};


int main()
{
    Matrix A(7, 7);
    // Copy specified matrix.
    int vals[49] = {0, 1, 1, 0, 0, 0, 0,
                0, 0, 1, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0,
                0, 0, 1, 0, 1, 1, 0,
                1, 1, 1, 0, 0, 1, 0,
                1, 0, 1, 0, 0, 0, 0,
                1, 1, 1, 1, 1, 1, 0};
    
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            A.set_elem(i, j, vals[i*7 + j]);
        }
    }

    // Initialise alpha and beta and set all elements to 1.
    Matrix alpha(7, 1);
    Matrix beta(7, 1);

    for (int i = 0; i < 7; i++)
    {
        alpha.set_elem(i, 0, 1);
        beta.set_elem(i, 0, 1);
    }

    // Run the algorithm with required parameters
    Algorithm algo(100, pow(10, -6), alpha, beta, A);
    algo.run();

    return 0;
}