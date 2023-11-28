#include <stdio.h>
#include <stdlib.h>
// Related variables should be declared together in a block, and arrays should always be 
// kept alongsided their length. This can be achieved using Structs.


// Structures are passed by value, unlike arrays that are passed by reference.
// This means that modifying a variable of a struct in a function will have no effect on the actual value.
struct Student {
    int ID;
    char *name;
    int grade;
};

// This strcture allows an array to be stored with its length, making for more readable code.
struct Vector {
    int length;
    int *elements;
};

void printList(struct Vector x)
{
    for (int i = 0; i < x.length; i++)
    {
        printf("%d ", x.elements[i]);
    }
    printf("\n");
}

int main()
{
    struct Student James;
    James.ID = 8;
    James.name = "James";
    James.grade = 100;

    // The above can be done in one line: struct Student James = {8, "James", 100};
    printf("%s\n", James.name);
    printf("-------------------------\n");
    struct Vector v1 = {10, calloc(10, 10 * sizeof(int))};
    for (int i = 0; i < v1.length; i++)
    {
        v1.elements[i] = i+1;
    }

    printList(v1);

    return 0;
}