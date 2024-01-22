#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>


int find_min_index(int a[], int len)
{
    int ai = 0;
    int minValue;
    int minIndex;
    while (a[ai] == -1)
    {
        ai++;
    }
    minValue = a[ai];
    minIndex = ai;
    for (int i = 1; i < len; i++)
    {
        if ((a[i] < minValue) && (a[i] != -1))
        {
            minValue = a[i];
            minIndex = i;
        }
    } 
    printf("Next min value: %d\n", minValue);
    return minIndex;
}
void printArray(int arr[], int len)
{
    printf("[");
    for (int i = 0; i < len; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("]\n");
}
void minimum5(int a[], int len, int indices[])
{
    int copy[len];
    for (int i = 0; i < len; i++)
    {
        copy[i] = a[i];
    }
    for (int i = 0; i < 5; i++)
    {
        int index = find_min_index(copy, len);
        indices[i] = index;
        copy[index] = -1;
    }
    printArray(indices, 5);
}



int main()
{
    int test[] = {9, 4, 6, 2, 3, 87, 8, 2, 1, 99, 6, 4, 5};
    int testB[5];
    minimum5(test, 13, testB);
    return 0;
}
