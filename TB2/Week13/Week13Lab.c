#include <stdio.h>
#include <stdlib.h>

// swap two elements in an array 
void swap(int array[], int i, int j){
    printf("Swapping element %d with element %d\n", i, j);
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

}

// find the index of the largest element in an array
int find_max_idx(int array[], int len){
    int max = array[0];
    int maxIndex = 0;
    for (int i = 1; i < len; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            maxIndex = i;
        }
    }
    printf("The largest element is %d\n", max);
    return maxIndex;
}

// print an array
void print_array(int array[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// sort an array
void sort(int array[], int len){
    for (int i = 1; i < len; i++)
    {
        int max_idx = find_max_idx(array, len - i + 1);
        swap(array, max_idx, len-i);
    }
}

// recursive version
void sort_v2(int array[], int len){
    int max_idx = find_max_idx(array, len);
    swap(array, max_idx, len-1);
    if (len > 1)
    {
        sort_v2(array, len-1);
    }
}

// selection sort: loop version
void sort_sel_loop(int array[], int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[i])
            {
                swap(array, i, j);
            }
        }
    }
}

// selection sort: recursive version
void sort_sel_rec(int array[], int len){
    if (len <= 1)
    {
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (array[i] > array[len-1])
        {
            swap(array, i, len-1);
        }
    }
    sort_sel_rec(array, len - 1);
}

int main()
{
    int array[] = {5, 35, 3,2,4};
    int len = 4;
    
    printf("testing find_max_idx-----------------------\n");
    // testing find_min_idx
    int min_idx = find_max_idx(array, len);
    printf("max_idx: %d\n", min_idx);

    printf("testing swap-----------------------\n");
    //testing swap
    swap(array, 0, 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("testing sort-----------------------\n");
    //test sort
    int a [] = {5, 3, 2, 1, 2, 4};
    len = 6;
    print_array(a, len);
    sort(a, len);
    print_array(a, len);

    int b [] = {5, 3, 2, 1, 2, 4};
    printf("testing sort (recursive)-----------------------\n");
    print_array(b, len);
    sort_v2(b, len);
    print_array(b, len);

    int c [] = {5, 3, 2, 1, 2, 4};
    printf("testing selection sort (recursive)-----------------------\n");
    print_array(c, len);
    sort_sel_rec(c, len);
    print_array(c, len);

    int d [] = {5, 3, 2, 1, 2, 4};
    printf("testing selection sort (loop)-----------------------\n");
    print_array(d, len);
    sort_sel_loop(d, len);
    print_array(d, len);
    return 0;
}