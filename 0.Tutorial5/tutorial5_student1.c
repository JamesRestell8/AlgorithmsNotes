#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <limits.h>

///////////////////////////////////////////////////////////////
/* Some helper functions  */
///////////////////////////////////////////////////////////////

void rand_populate_array(int array[], int len, int lower, int upper)
{
  int size = upper - lower; 
  for(int i = 0; i < len; i++){
    array[i] = lower + (rand() % size);  
  }
  return; 
}

void print(int a[], int len)
{
  printf("[");
  for (int i = 0; i < len; i++){
    printf("%d", a[i]);
    if (i < (len - 1)){
      printf(", ");
    }
    else{
      printf("]");
    }
  }
  return; 
}

///////////////////////////////////////////////////////////////
/* End of  helper functions  */
///////////////////////////////////////////////////////////////

int find_max(int arr[], int len)
{
  int max = arr[0];
  for (int i = 1; i < len; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int find_min(int arr[], int len)
{
  int min = arr[0];
  for (int i = 1; i < len; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
  }
  return min;
}


int find_min_idx(int arr[], int len){
  int min_val = arr[0];
  int min_idx = 0; 
  for (int i = 1; i < len; i++)
  {
    if (arr[i] < min_val)
    {
      min_val = arr[i];
      min_idx = i;
    }
  }
  return min_idx;
}

int find_second_smallest(int arr[], int len)
{
  int *copy = malloc(len * sizeof(int));
  for (int i = 0; i < len; i++)
  {
    copy[i] = arr[i];
  }
  copy[find_min_idx(copy, len)] = INT_MAX;
  return find_min(copy, len);
}

int find_second_smallest2(int arr[], int len)
{
  // WRITE OUT THE BODY OF THIS FUNCTION
  // INCLUDING THE RETURN VALUE
  return 0; 
}

void find_smallest(int arr[], int len, int vals[], int k)
{
  int *copy = malloc(len * sizeof(int));
  for (int i = 0; i < len; i++)
  {
    copy[i] = arr[i];
  }
  for (int i = 0; i < k; i++)
  {
    int currentMin = find_min(copy, len);
    copy[find_min_idx(copy, len)] = INT_MAX;
    vals[i] = currentMin;
  }
  print(vals, k); 
}

int main()
{
  /* Reseed the random number generator at each run[I] */
  srand(time(NULL));
  int len_A = 15, lower_A = 5, upper_A = 25;
  int len_B = 12, lower_B = -10, upper_B = 11;
  int len_K = len_A / 3; 
  int arr_A[len_A], arr_B[len_B];
  // I've defined vals differently for the student version
  // so that it is populated with zeros (and not junk) 
  int* vals = calloc(len_K, sizeof(int));
  int min, max, sec_min1, sec_min2; 
  rand_populate_array(arr_A, len_A, lower_A, upper_A);
  rand_populate_array(arr_B, len_B, lower_B, upper_B); 
  printf("The random array A is: "); 
  print(arr_A, len_A);
  printf("\n");

  min = find_min(arr_A, len_A);
  max = find_max(arr_A, len_A);
  sec_min1 = find_second_smallest(arr_A, len_A);
  sec_min2 = find_second_smallest2(arr_A, len_A);
  find_smallest(arr_A, len_A, vals, len_K); 
  printf("\nThe minimum value in the array A is: %d", min);
  printf("\nThe maximum value in  array A is:  %d", max);
  int lengthOne[] = {1};
  printf("\nThe minimum value in the array [1] is: %d", find_min(lengthOne, 1));
  printf("\n(Version 1)The second least value in the array A is: %d", sec_min1);
  printf("\n(Version 2)The second least value in the array A is: %d", sec_min2);
  printf("\nThe smallest %d values in array A are: ", len_K);
  print(vals, len_K);
  printf("\n");
  
  printf("\n\nThe random array B is: "); 
  print(arr_B, len_B);
  printf("\n");
  min = find_min(arr_B, len_B);
  max = find_max(arr_B, len_B);
  printf("The minimum value in  array B is: %d", min);
  printf("\nThe maximum value in  array B is: %d\n", max);

  return 0; 
}
