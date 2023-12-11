#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

struct matrix
{
    int numrow;
    int numcol;
    int *elements;
};
typedef struct matrix Matrix;

/*
Print an image to the console. 
image: an array stores the flattened image stored in row major order.
Height: the height of the image.
Width: the width of the image.
*/
void image2char(int image[], int Height, int Width)
{
    for (int i = 0; i < Height*Width; i++)
    {
        if (i % Width == 0)
        {
            printf("\n");
        }
        if (image[i] < 50)
        {
            printf(" ");
        } else if (image[i] < 150)
        {
            printf("I");
        } else
        {
            printf("M");
        }
    }
}


/*
Read a matrix from file. Don't change it!
filename: the file that contains the matrix.
return: a matrix structure containing the matrix.
*/
Matrix read_matrix(char *filename)
{
    FILE *f = fopen(filename, "rb");
    // read int variables to the file.
    int numrow = getw(f);
    int numcol = getw(f);
    Matrix M = {numrow, numcol, calloc(numrow * numcol, sizeof(int))};

    for (int i = 0; i < M.numrow; i++)
    {
        for (int j = 0; j < M.numcol; j++)
        {
            M.elements[i*numcol + j] = getc(f);
        }
    }

    fclose(f);
    return M;
}

/*
Retrieve an element from a matrix.
M: the matrix.
i,j: the row and column of the element.
return: the element at row i and column j.
*/
int get_elem(Matrix M, int i, int j)
{
    return M.elements[i*M.numcol + j];
}

/*
Assign value to an element in a matrix.
M: the matrix.
i,j: the row and column of the element.
value: the value to be assigned.
*/
void set_elem(Matrix M, int i, int j, int value)
{
    M.elements[i*M.numcol + j] = value;
}

/*
Computes the pairwise distance between arrays a and b of length len.
*/
int pairwise_dist2(int a[], int b[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        int distance = a[i] - b[i];
        sum += distance * distance;
    }
    return sum;
}

/*
function that returns the ith row of matrix x as an array.
*/
void getRow(Matrix X, int row, int answer[])
{
    for (int i = 0; i < X.numcol; i++)
    {
        answer[i] = get_elem(X, row, i);
    }
}

/*
Compute the pairwise squared distance of the i-th row of M1 and the j-th row of M2.
A: the first matrix.
B: the second matrix.
return: a matrix D where D_ij is the squared distance between the i-th row of M1 and the j-th row of M2.
*/
Matrix calculateMatrixD(Matrix A, Matrix B)
{
    int *elements = calloc(A.numrow * B.numrow, sizeof(int));
    Matrix D = {A.numrow, B.numrow, elements};

    for (int i = 0; i < D.numrow; i++)
    {
        for (int j = 0; j < D.numcol; j++)
        {
            // free memory for the row arrays, and initialise them with the correct values.
            int *A_ithRow = calloc(A.numcol, sizeof(int));
            int *B_jthRow = calloc(A.numcol, sizeof(int));
            getRow(A, i, A_ithRow);
            getRow(B, j, B_jthRow);

            // get the distance value and set the correct element of D equal to it.
            int distance = pairwise_dist2(A_ithRow, B_jthRow, A.numcol);
            D.elements[i*D.numcol + j] = distance;

            // free memory
            free(A_ithRow);
            free(B_jthRow);
        }
    }
    return D;
}

/*
Find the index of the minimum element in an array. 
a: the array.
len: the length of the array.
return: the index of the minimum element in the array.
example: [1,2,3,4,5] -> 0
        [5,4,3,2,1] -> 4
*/
int find_min_index(int a[], int len)
{
    // initialise variables
    int ai = 0;
    int minValue;
    int minIndex;

    // copy the array so that we aren't altering the original array.
    int *copy = calloc(len, sizeof(int));
    for (int i = 0; i < len; i++)
    {
        copy[i] = a[i];
    }

    // we will be setting certain values to -1, but we wan't to ignore them when searching for the minimum index.
    while (copy[ai] == -1)
    {
        ai++;
    }

    // find the next minimum value and its corresponding index
    minValue = copy[ai];
    minIndex = ai;
    for (int i = 1; i < len; i++)
    {
        if ((copy[i] < minValue) && (copy[i] != -1))
        {
            minValue = copy[i];
            minIndex = i;
        }
    }
    free(copy);
    return minIndex;
}

/*
Useful function for testing.
*/
void printArray(int arr[], int len)
{
    printf("[");
    for (int i = 0; i < len; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("]\n");
}

/*
Find the indices of 5 minimum elements in an array.
a: the array.
len: the length of the array.
return: an array of 5 integers containing the indices of the 5 minimum elements in a.
example: [1,2,33,4,5,23,6] -> [0,1,3,4,6]
*/
void minimum5(int a[], int len, int indices[])
{
    // copy the array so that we aren't altering the initial array.
    int *copy = calloc(len, sizeof(int));
    for (int i = 0; i < len; i++)
    {
        copy[i] = a[i];
    }

    // run find_min_index 5 times, setting each value to -1 when it has been found, so that we ignore it next time
    for (int i = 0; i < 5; i++)
    {
        int index = find_min_index(copy, len);
        indices[i] = index;
        copy[index] = -1;
    }
    free(copy);
}

int main()
{
    // 10% for submitting the correct code.
    Matrix X = read_matrix("./X.matrix");
    printf("N: %d, M: %d\n", X.numrow, (int) sqrt(X.numcol));   

    Matrix T = read_matrix("./T.matrix");
    printf("L: %d\n", T.numrow);

    Matrix Y = read_matrix("./Y.matrix");
    int s = 0;
    for (int i = 0; i < Y.numrow; i++)
    {
        if(Y.elements[i*Y.numcol + 0] == 1)
            s++;
    }
    printf("Number of 1 in the training set: %d\n", s);

    //construct the matrix D, where D_ij is the squared distance between the i-th row of T and the j-th row of X.
    Matrix D = calculateMatrixD(T, X);
    
    // 40% of the total score.
    // 15% for the helper functions.
    // 25% for the pairwise_dist2 function.
    int totalOnesFound = 0;
    for(int i=0; i< T.numrow; i++){
        printf("The %d-th testing image:\n", i);

        //visualise the i-th testing image. 
        int *T_ithRow = calloc(T.numcol, sizeof(int));
        for (int a = 0; a < T.numcol; a++)
        {
            T_ithRow[a] = get_elem(T, i, a);
        }
        image2char(T_ithRow, sqrt(T.numcol), sqrt(T.numcol));

        //find the indices of the 5 smallest elements in the i-th row of D.
        int *smallestFiveIndices = calloc(5, sizeof(int));
        // define an array containing the i-th row of D
        int *D_ithRow = calloc(X.numrow, sizeof(int));
        for (int j=0; j<X.numrow; j++)
        {
            D_ithRow[j] = get_elem(D, i, j);
        }
        minimum5(D_ithRow, X.numrow, smallestFiveIndices);

        // get labels
        int labels[5];
        for (int k = 0; k < 5; k++)
        {
            labels[k] = get_elem(Y, smallestFiveIndices[k], 0);
        }

        // count the number of ones
        int numOne = 0;
        for (int z = 0; z < 5; z++)
        {
            if (labels[z] == 1)
            {
                numOne++;
            }
        }

        printf("\nThe %d-th testing image is classified as", i);
        // print out your prediction.
        if (numOne >= 3)
        {
            printf(" 1");
            totalOnesFound++;
        } else
        {
            printf(" not 1");
        }
        // 15% of the total score.
        printf("\n");
        printf("----------------------------------------\n");
        free(smallestFiveIndices);
        free(D_ithRow);
        free(T_ithRow);
    }

    // did you free the memory that allocated in your program?
    // - 5% for every missing free.
    free(X.elements);
    free(T.elements);
    free(Y.elements);
    free(D.elements);
    printf("Total ones found: %d\n", totalOnesFound);
    return 0;
}