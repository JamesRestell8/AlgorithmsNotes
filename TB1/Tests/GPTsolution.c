#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure definition for matrix
struct matrix {
    int numrow;
    int numcol;
    int *elements;
};

// Typedef for convenience
typedef struct matrix Matrix;

// Function to calculate squared Euclidean distance between two rows of matrices
double squaredEuclideanDistance(const int *rowA, const int *rowB, int numcol) {
    double distance = 0.0;

    for (int i = 0; i < numcol; ++i) {
        double diff = rowA[i] - rowB[i];
        distance += diff * diff;
    }

    return distance;
}

// Function to form a new matrix D with squared Euclidean distances
Matrix calculateDistanceMatrix(const Matrix *A, const Matrix *B) {
    Matrix D;
    D.numrow = A->numrow;
    D.numcol = B->numrow; // Assuming the number of columns in B is the number of rows in the resulting matrix D
    D.elements = (int *)malloc(D.numrow * D.numcol * sizeof(int));

    for (int i = 0; i < D.numrow; ++i) {
        for (int j = 0; j < D.numcol; ++j) {
            // Calculate squared Euclidean distance between rows i of A and j of B
            double distance = squaredEuclideanDistance(
                &(A->elements[i * A->numcol]),
                &(B->elements[j * B->numcol]),
                A->numcol
            );
            // Store the result in matrix D
            D.elements[i * D.numcol + j] = (int)distance;
        }
    }

    return D;
}

// Function to print a matrix
void printMatrix(const Matrix *mat) {
    for (int i = 0; i < mat->numrow; ++i) {
        for (int j = 0; j < mat->numcol; ++j) {
            printf("%d ", mat->elements[i * mat->numcol + j]);
        }
        printf("\n");
    }
}

// Function to free memory allocated for a matrix
void freeMatrix(Matrix *mat) {
    free(mat->elements);
}

int main() {
    // Example usage
    int X = 3; // Number of rows
    int Y = 2; // Number of columns

    // Example matrices (replace with your actual matrices)
    Matrix A = {X, Y, (int[]){1, 2, 3, 4, 5, 6}};
    Matrix B = {X, Y, (int[]){7, 8, 9, 10, 11, 12}};

    // Calculate matrix D with squared Euclidean distances
    Matrix D = calculateDistanceMatrix(&A, &B);

    // Print the result
    printf("Matrix D:\n");
    printMatrix(&D);

    // Free allocated memory
    freeMatrix(&D);

    return 0;
}
