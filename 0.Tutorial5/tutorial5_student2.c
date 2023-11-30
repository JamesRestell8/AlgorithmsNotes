#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <limits.h>


struct vector {
  int len;
  int* elements; 
};

typedef struct vector Vector; 

void print_vec(Vector v)
{
  printf("[");
  for (int i = 0; i < v.len; i++){
    printf("%d", v.elements[i]);
    if (i < (v.len - 1)){
      printf(", ");
    }
  }
  printf("]");
  return; 
}

Vector make_random_vec(int len, int lower, int upper)
{
  int size = upper - lower; 
  Vector v;
  v.len = len;
  v.elements = calloc(len, sizeof(int));
  for(int i = 0; i < v.len; i++){
    v.elements[i] = (rand() % size); 
  }
  return v; 
}

struct matrix {
  int nrow;
  int ncol;
  int* elements;
};
typedef struct matrix Matrix;

/*
 * idx: return (flattened) index of i,j element of row-major matrix M
 */
int idx(Matrix M, int i, int j){
  return i * M.ncol + j;
}

int get_elem(Matrix M, int i, int j){
  return M.elements[idx(M, i, j)];
}

void set_elem(Matrix M, int i, int j, int val){
  M.elements[idx(M, i, j)] = val;
}

void print_mat(Matrix M){
  for(int i = 0; i < M.nrow; i++){
    for(int j = 0; j < M.ncol; j++){
      printf("%d ", get_elem(M, i, j));
    }
    printf("\n");
  }
}

Matrix make_random_mat(int num_rows, int num_cols, int lower, int upper)
{
  int size = upper - lower;
  int size_M; 
  Matrix M;
  M.nrow = num_rows;
  M.ncol = num_cols;
  size_M = num_rows * num_cols;
  M.elements = calloc(size_M, sizeof(int)); 
  for(int k = 0;  k < size_M; k++){
    M.elements[k] =  (rand() % size); 
  }
return M; 
}

Vector get_row(Matrix M, int i){
  Vector v;
  // WRITE OUT THE BODY OF THIS FUNCTION
  
  return v; 
}

Vector get_col(Matrix M, int j)
{
  Vector v;
  // WRITE OUT THE BODY OF THIS FUNCTION

  return v; 

  
}

void print_mat2(Matrix M){
  for(int i = 0; i < M.nrow; i++){
    print_vec(get_row(M, i)); // print i-th row of M
    printf("\n");
  }
  return; 
}


int main()
{
  srand(time(NULL));
  int num_rows = 3, num_cols = 5;
  int row_n = 1, col_n = 2;  
  int len = 15, lower = 0, upper = 10;  
  Vector v = make_random_vec(len, lower, upper);
  printf("The random vector v is: ");
  print_vec(v);
  printf("\n"); 

  Matrix M = make_random_mat(num_rows, num_cols, lower, upper);
  printf("(Print version 1)The random matrix M is:\n\n");
  print_mat(M);
  printf("\n"); 

  Vector row = get_row(M, row_n);
  Vector col = get_col(M, col_n);
  printf("Row number %d of M is: ", row_n + 1);
  print_vec(row);
  printf("\n"); 
  printf("Column number %d of M is: ", col_n + 1);
  print_vec(col);
  printf("\n"); 

  //////////////////////////////////////////////
  // Once get_row is defined Version 2 will work
  // so you can just uncomment the code below
  /////////////////////////////////////////////
  
  // printf("\n(Print version 2)The random matrix M is:\n\n");
  // print_mat2(M);
  // printf("\n\n"); 
  
  return 0; 
}
