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
Compute the pairwise squared distance of the i-th row of M1 and the j-th row of M2.
M1: the first matrix.
M2: the second matrix.
return: a matrix D where D_ij is the squared distance between the i-th row of M1 and the j-th row of M2.
*/
int pairwise_dist2(int a[], int b[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += pow((a[i] - b[i]), 2);
    }
    return sum;
}

void pairwise_dist(Matrix M1, Matrix M2, Matrix D)
{
    // iterate through each element of D and set it to be the pairwise distance between the i-th row of M1 and the j-th row of M2
    for (int i = 0; i < D.numrow; i++)
    {
        for (int j = 0; j < D.numcol; j++)
        {
            int M1_ithRow[M1.numcol];
            int M2_jthRow[M2.numcol];
            for (int k = 0; k < M1.numcol; k++)
            {
                M1_ithRow[k] = get_elem(M1, i, k);
                M2_jthRow[k] = get_elem(M1, j, k);
            }
            set_elem(D, i, j, pairwise_dist2(M1_ithRow, M2_jthRow, M1.numcol));
        }
    }
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
    int minValue = a[0];
    int minIndex = 0;
    for (int i = 1; i < len; i++)
    {
        if (a[i] < minValue)
        {
            minValue = a[i];
            minIndex = i;
        }
    } 
    return minIndex;
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
    int copy[len];
    for (int i = 0; i < len; i++)
    {
        copy[i] = a[i];
    }
    for (int i = 0; i < 5; i++)
    {
        int index = find_min_index(copy, len);
        indices[i] = index;
        copy[index] = INT16_MAX;
    }
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

    //TODO: construct the matrix D, where D_ij is the squared distance between the i-th row of T and the j-th row of X.
    // 40% of the total score.
    // 15% for the helper functions.
    // 25% for the pairwise_dist2 function.

    int *dElements = calloc(T.numrow * X.numrow, sizeof(int));
    Matrix D = {T.numrow, X.numrow, dElements};
    pairwise_dist(T, X, D);

    for(int i=0; i< T.numrow; i++){ // replace 0 with T.numrow.
        printf("The %d-th testing image:\n", i);
        //TODO: visualise the i-th testing image, optional. 
        int *T_ithRow = calloc(T.numcol, sizeof(int));
        for (int a = 0; a < T.numcol; a++)
        {
            T_ithRow[a] = get_elem(T, i, a);
        }
        image2char(T_ithRow, sqrt(T.numcol), sqrt(T.numcol));
        //TODO: find the indices of the 5 smallest elements in the i-th row of D.
        // 15% of the total score.

        int smallestFiveIndices[5];
        int D_ithRow[X.numrow];
        for (int j=0; j<X.numrow; j++)
        {
            D_ithRow[j] = get_elem(D, i, j);
        }
        minimum5(D_ithRow, X.numrow, smallestFiveIndices);

        int labels[5];
        for (int k = 0; k < 5; k++)
        {
            labels[k] = get_elem(Y, smallestFiveIndices[k], 0);
        }

        int numOne = 0;
        for (int z = 0; z < 5; z++)
        {
            if (labels[z] == 1)
            {
                numOne++;
            }
        }

        printf("The %d-th testing image is classified as", i);
        //TODO: print out your prediction.
        if (numOne >= 3)
        {
            printf(" 1");
        } else
        {
            printf(" not 1");
        }
        // 15% of the total score.
        printf("\n");
        printf("----------------------------------------\n");
    }

    // did you free the memory that allocated in your program?
    // - 5% for every missing free.
    free(X.elements);
    free(T.elements);
    free(Y.elements);
    return 0;
}