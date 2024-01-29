#include <stdio.h>
#include <stdlib.h>
// C does not support OOP, it only has structures which are not sufficent for OOP.
// This is a C++ file. C++ is a superset of C, so all C files will compile in C++ but not the other way around.

class Student
{
    int ID;
    const char* name;
    int grade;
    
    public: // by default, all class attributes are private, you need to decalre the public ones like this.
    // It is good practice to keep variables private and have public getters and setters so that data
    // can't be corrupted.

    // CONSTRUCTORS are methods that initialise an object of the class. They have no return type, and are just 
    // named with the same name as the class.
    Student(int newId, const char* newName, int newGrade)
    {
        ID = newId;
        name = newName;
        if ((newGrade <= 100) && (newGrade >= 0))
        {
            grade = newGrade;
        }
    }


    // Methods are defined as normal like so:
    int getGrade()
    {
        return grade;
    }
    void setGrade(int newGrade)
    {
        if ((newGrade <= 100) && (grade >= 0))
        {
            grade = newGrade;
        }
    }
}; // semicolon needed at end of class definition.


int main()
{
    Student james(1, "James Restell", 85);
    printf("%d\n", james.getGrade());
    james.setGrade(99);
    printf("%d\n", james.getGrade());
    return 0;
}