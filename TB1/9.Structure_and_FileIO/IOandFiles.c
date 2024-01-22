#include <stdio.h>
#include <stdlib.h>

// Here we are focusing on file IO - we have already seen printf and scanf for the command line.

// FILE *fopen(char *filename, char *mode) returns a pointer to a FILE structure.
// after read/write operations on a file, you must close it using:
// fclose(FILE * file), where the input is the pointer from fopen().

// IO functions can only read/write the next "thing" in the IO stream.
// The FILE * pointer indicates our current position in the stream.

// To read the next byte, we use fgetc(FILE * file), which returns the next byte in the stream as an int variable.
// To write the next byte, we use fputc(int byte, FILE * file), where byte is what we want to write.

// To read the next line, we use char *fgets(char *line, int max, FILE * file) where line is a pointer to where the
// line should be stored, and max is the maximum number of characters to be read.

// We can write a formatted string using int fprintf(FILE *file, char *line, variables)
// where line is the formatted string, and variables is the variables to replace the specifiers in line
// e.g. fprintf(file, "pi is %.2f.\n", 3.14) writes "pi is 3.14" to file.

// feof(FILE *file) returns 0 you aren't at the end of the file, and a non-zero value if you are.
int main()
{
    // example where we read a text file line by line.
    FILE *f = fopen("poem.txt", "r");
    char line[1024];
    while (1){ // loop forever until reach the end
        fgets(line, 1024, f); // read the next line
        if (feof(f)){
            printf("%s\n", line);
            break;// stop the loop if we are at
        // the end of the file
        }
        //print the line to screen
        printf("%s", line);
    }
    fclose(f); 
    return 0;
}