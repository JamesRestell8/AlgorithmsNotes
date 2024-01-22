#include <stdio.h>

struct student{
    int ID;
    char *name;
    int grade;
};

void printStudent(struct student stu)
{
    printf("ID: %d, Name: %s, Grade: %d\n", stu.ID, stu.name, stu.grade);
}

//TODO: define a function that takes an array of student structs and prints out the info of students who have a grade > 40
// one student per line. 
void printAboveForty(struct student students[], int length)
{
    for (int i = 0; i < length; i++)
    {
        struct student currentStudent = students[i];
        if (currentStudent.grade > 40)
        {
            printStudent(currentStudent);
        }
    }
}


int main(){
    struct student song; //declare a student variable
    //initialize
    song.ID = 1024; 
    song.name = "song liu";
    song.grade = 39; 

    printf("%s\n", song.name); //displays "song liu"
    
    //declare + initialize in one line. 
    struct student song2 = {1000, "song liu", 41};

    printf("%s\n", song2.name); //displays "song liu"


    printf("-------------\n");
    printStudent(song);
    printStudent(song2);
    printf("-------------\n");

    struct student James = {2048, "James Restell", 98};
    struct student students[] = {song, song2, James};
    printAboveForty(students, 3);

    return 0;
}