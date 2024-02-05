#include <stdio.h>
#include <string.h> // for string compare function 'strcmp'

// SORTING STRINGS
/*
** swap: swap the i and j elements of an array of strings
*/
void swap(char* array[], int i, int j){
    // YOUR CODE HERE
}

/*
** find_max_idx: find the index of the "largest" string in array
*/
int find_max_idx(char* array[], int len){
    return -1;
}

void print_array(char* array[], int len){
    for(int i = 0; i < len; i++){
        printf("%s; ", array[i]);
    }
    printf("\n");
}

/*
** sort: sort array of strings in ascending order
*/
void sort(char* array[], int len){
  // YOUR CODE HERE
}

/*
** sort_v2: sort array of strings in ascending order using a *recursive* algorithm
*/
void sort_v2(char* array[], int len){
  // YOUR CODE HERE
}


// STRING COMPARISON
/*
** my_strcmp: return <0 if s<t, 0 if s==t, >0 if s>t
*/
int my_strcmp(char* s, char* t){
    return strcmp(s, t);
}

void my_print(char* s){
    int i = 0;
    while(s[i] != "\0"){
        printf("%c", s[i]);
        i++;
    }
}

// ...USING POINTERS
void my_print2(char* s){
    while(*s != "\0"){
        printf("%c", *s);
        s++;
    }
}

int main(){
    // MAKE SOME STRINGS
    char* s1 = "string 1";
    char* s2 = "hello, world!";
    char* s3 = "about";
    char* s4 = "zebra";
    int len = 4;

    // TEST SORT
    printf("TESTING sort\n\n");
    char* arr1[] = {s1, s2, s3, s4};
    // YOUR CODE HERE
    print_array(arr1, 4);
    printf("\n\n");
    
    printf("TESTING sort2\n\n");
    char* arr2[] = {s1, s2, s3, s4};
    // YOUR CODE HERE
    print_array(arr2, 4);
    printf("\n\n");

    printf("TESTING my_strcmp\n\n");
    printf("%d \n", my_strcmp(s3, s4));
    return 0;
}
