#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <iostream>
#include <cstdlib>

class Matrix{
    //TODO: Write a matrix class with three private fields: 
    //  num_rows: integer, stores the number of rows 
    //  num_cols: integer, stores the number of columns
    //  elements: integer pointer, pointing to a contiguous memory stores a row-major matrix.
    
    int num_rows;
    int num_cols;
    int *elements;
    
    // all functions below must be PUBLIC!
    
    public: 
    
        //TODO: Write set_elem and get get_elem functions. Must check for invalid indices.
        // Use zero-based indexing!

        bool isInt(double x)
        {
            return (x == int(x));
        }

        void set_elem(int i, int j, int value){
            if (i < 0 || i >= num_rows || j < 0 || j >= num_cols){
                printf("invalid indices!\n");
            } else {
                elements[i * num_cols + j] = value;
            }
        }
    
        int get_elem(int i, int j){
            if (i < 0 || i >= num_rows || j < 0 || j >= num_cols){
                printf("invalid indices!\n");
            } else {
                return elements[i * num_cols + j];
            }
            return -999999999;
        }
    
        //TODO: Write an add function. Must check for invalid dimensions.
    
        void add(Matrix B){
            if (num_rows != B.num_rows || num_cols != B.num_cols){
                printf("invalid dimensions!\n");
            } else {
                for (int i = 0; i < num_rows; i++){
                    for (int j = 0; j < num_cols; j++){
                        set_elem(i, j, get_elem(i, j) + B.get_elem(i, j));
                    }
                }
            }
        }
    
        //TODO: Write a constructor, which takes three arguments: nrow, ncol, and elem.
        // Must check nrow and ncol are positive integers. If they are not, print "invalid dimensions!" and do nothing.
    
        Matrix(int nrow, int ncol){
            if (nrow <= 0 || ncol <= 0){
                printf("invalid dimensions!\n");
            } else {
                num_rows = nrow;
                num_cols = ncol;
                elements = (int*) calloc(num_rows*num_cols, sizeof(int));
            }
        }

        ~Matrix()
        {
            free(elements);
        }

        int get_num_rows()
        {
            return num_rows;
        }

        int get_num_cols()
        {
            return num_cols;
        }

        // print out 
        void print(){
            for (int i = 0; i < num_rows; i++){
                for (int j = 0; j < num_cols; j++){
                    printf("%d ", get_elem(i, j));
                }
                printf("\n");
            }
        }
};

// reading image from a file. Do not change. 
void read_image(int image[])
{
    FILE *in = fopen("surprise.dat", "rb");
    int count = 0;
    unsigned char b = fgetc(in);
    while (!feof(in))
    {
        image[count] = b;
        b = fgetc(in);
        count++;
    }
    fclose(in);
}

// TODO: write your image class below
class Image : public Matrix
{
    public:
        Image(int height, int width, int *data) :Matrix(height, width)
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    set_elem(i, j, data[j + i*height]);
                }
            }
        }

        void show()
        {
            for (int i = 0; i < get_num_rows() * get_num_cols(); i++)
            {
                if (i % get_num_cols() == 0)
                {
                    printf("\n");
                }
                if (get_elem(floor(i / get_num_cols()), i % get_num_rows()) < 50)
                {
                    printf(" ");
                } else if (get_elem(floor(i / get_num_cols()), i % get_num_rows()) < 150)
                {
                    printf("I");
                } else
                {
                    printf("M");
                }
            }
        }
};


int main()
{
    int HEIGHT = 45; 
    int WIDTH = 44;
    int *data = (int *)malloc(HEIGHT * WIDTH * sizeof(int));

    // load the image to the data. Do not change the following line.
    read_image(data);

    // TODO: write test code for your image class
    Image *img = new Image(HEIGHT, WIDTH, data);
    img->show();
    // do not change the following line.
    free(data);
    free(img);

    return 0;
}
