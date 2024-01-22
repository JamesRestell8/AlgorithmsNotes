#include <stdio.h>
#include <stdlib.h>

// A pointer is a variable that stores the location of another variable in virtual memory.


int main()
{
    // The & symbol is the reference operator, and returns the location of the variable
    int a = 0;
    printf("The address of a is %p\n", &a);

    // The * symbolol is the dereference operator, and returns the value stored in a loaction
    int b = 1;
    int *pb = &b;
    int c = *pb;

    printf("The value stored in %p is %d\n", pb, c);

    // You should never initialise a pointer indirectly like int *pa;
    // If you don't know what you want yet, do this:
    int *nullPointer = NULL;

    // Variables take up more that one bit, but if you add one to a pointer, it will
    // automatically add enough bytes to take you to the next variable
    int x = 1;
    int *px = &x;
    int *py = px + 1;

    printf("%p\n", px);
    printf("%p\n", py);

    // px and py are 4 bytes apart, even though we only added one, because an int takes up 4 bytes

    return 0;
}