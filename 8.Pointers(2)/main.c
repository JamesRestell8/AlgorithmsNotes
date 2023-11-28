#include <stdio.h>
#include <stdlib.h> // this library is needed to dynamically allocate memory

// so far, we have used stack memory for our variables, where memory is allocated at compile time
// heap memory allows the programmer to allocate memory at runtime, giving you more flexibility
// for the size of your variables. However, this memory has to be managed manually and freed up manually.


int main()
{
    // Example: an array where the length is unknown at compile time:
    printf("How many customers today?:\n");
    int numCustomers;
    scanf("%d", &numCustomers);

    // we now allocate memory for the array using heap memory
    // malloc returns a pointer pointing to the start of the allocated memory
    int *pCustomerRatings = malloc(numCustomers * sizeof(int));

    // IMPORTANT: all manually allocated memory must be freed by the end of the program
    free(pCustomerRatings);

    // Using calloc will not only allocate memory but also clear all the memory
    // of the garbage values it was previously holding.
    // Note that it takes number and size as seperate parameters as opposed to malloc.
    int *usingCalloc = calloc(numCustomers, sizeof(int));
    free(usingCalloc);

    // Using realloc - starting with a 10 element array
    int *array =  malloc(10*sizeof(int));
    // We can now expand it to a 20-element array using realloc:
    array =  realloc(array, 20*sizeof(int));
    free(array);
    // This isn't the most efficient/proper way to do this, good to be aware of it though.

    return 0;
}