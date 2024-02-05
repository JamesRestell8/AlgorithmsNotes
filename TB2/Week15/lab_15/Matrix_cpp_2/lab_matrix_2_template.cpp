#include <stdio.h>
#include <stdlib.h>
#include <climits>

class matrix
{
    // TOOD: copy and paste your matrix class from the previous lab. 

    // TODO: modify it as instructed in the slides. 

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

int main()
{
    int HEIGHT = 45; 
    int WIDTH = 44;
    int *data = (int *)malloc(HEIGHT * WIDTH * sizeof(int));

    // load the image to the data. Do not change the following line.
    read_image(data);

    // TODO: write test code for your image class

    // do not change the following line.
    free(data);
}
