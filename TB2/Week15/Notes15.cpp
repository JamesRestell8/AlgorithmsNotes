#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

/*
The lifespan of an object is a complicated topic in C++.
We only need to remember a few things:
    ▶ When your program finishes, all the objects you have created
    in the stack memory will be automatically destroyed.
    ▶ In the same function, objects will be destroyed in the opposite
    order they are created (last in first out).
    ▶ An object created in the stack memory of a function will be
    destroyed when the function exits unless it is the return value.
    ▶ An object created in the heap memory will not be destroyed
    until it is manually freed by the programer.
*/

class Matrix{
    int numrows;
    int numcols;
    int *elements;

    public:
        Matrix(int nrows, int ncols){
            numrows = nrows;
            numcols = ncols;
            printf("creating matrix...\n"); //alloc heap mem
            elements = (int*) malloc(nrows*ncols*sizeof(int));
        }
        // Below is the DECONSTRUCTOR. It is called when the object is destroyed (normally at the end of the program).
        ~Matrix(){
            //free memory
            printf("freeing matrix...\n");
            free(elements);
        }
};

class student{
    int ID;
    const char* name;
    int grade;
    public:
        student(int newID, const char* newname, int newgrade){
            ID = newID;
            name = newname;
            //checking the validity of the grade
            if(newgrade <= 100 && newgrade > 0){
                grade = newgrade;
            }
        }
        void set_grade(int newgrade)
        {
            grade = newgrade;
        }

        int get_grade()
        {
            return grade;
        }
};

// WE NOW WANT TO MAKE A CHILD CLASS OF STUDENT CALLED CSSTUDENT AS FOLLOWS:
// This will inherit all methods and attributes from student as well as new ones defined for this specifically
// The constructor is NOT inherited. You need to write a new one.
// ALL FUNCTIONS THAT TAKE STUDENT AS AN INPUT WILL NOW ALSO ACCEPT CSSTUDENT OBJECTS.

class CSstudent: public student
{
    int programming_grade;
    public:
        CSstudent(int newid, const char* newname, int newgrade, int p_grade) :student(newid, newname, newgrade) // calling the constructor in the parent class
        {
            programming_grade = p_grade;
            // validity checking omitted
        }
        int get_programming_grade(){
            return programming_grade;
        }
        void set_programming_grade(int grd){
            if(grd <= 100 && grd > 0){
                programming_grade = grd;
            }
        }
};

int main()
{
    Matrix m(2,2);
    printf("Program running...\n");

    // You can also create objects on heap memory using
    Matrix *pm = new Matrix(2,2);
    // You have to manually delete objects created on heap memory
    delete pm;

    return 0;
}