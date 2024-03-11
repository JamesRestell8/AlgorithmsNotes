vd <- c(1, 2, 3, 4) # using the combine operator to make vector
vi <- c(1L, 2L, 3L, 4L) # makes a vector of different type

class(vd)
class(vi)

# Initialising vectors of desired types:
x <- numeric(4)
y <- integer(4)
z <- logical(4)
c <- character(4)
x
y
z
c

# Creating sequences:
a <- 1:3 # 1 2 3
b <- 3:-3 # 3 2 1 0 -1 -2 -3

# Sequences different way
seq(1.5, 3.5, by = 0.5)
seq(3.5, 1.5, by = -0.5)
seq(1.5, 3.5, length.out = 6)

a <- c(1,2,3,4)
b <- c(1,2,3,4)
a+b # dimension wise addition
a-b
a / b
a * b # THIS IS NOT VECTOR MULTIPLICATION
a%*%b # THIS IS VECTOR MULTIPLICATION


a <- c(1,2,3,4)
a > 2 # Logical operation returns a vector of booleans

exp(c(1,2,3,4)) # Many functions operate on each element in the vector


a <- c(1,2,3,4)
sum(a) # self-explanatory

b <- c(4,3,2,1)
tcrossprod(a, b) # This computes ab^T

# VECTOR INDEXING STARTS FROM 1 NOT 0!
a <- c(1,2,3,4)
a[5] <- 10 # You can add to the vector like this



# It is generally better to allocate memory in advance:

# No memory allocation:
tic <- Sys.time()
x <- c(1)
for(ii in 2:1e6){
  x[ii] <- ii
}
Sys.time() - tic
# Time difference of 0.2227435 secs

# Memory allocation:
tic <- Sys.time()
x <- numeric(1e6)
for(ii in 2:1e6){
  x[ii] <- ii
}
Sys.time() - tic
# Time difference of 0.05552578 secs

# More than one index at a time
a <- c("a", "b", "c", "d")
b <- c(1,3,4)
a[b]

# Conditional indexing:
a <- c(7,2,1,5)
a[a>2]


# Getting help
?"*"
?":"
?"?"
?"%*%"
?mean

# Define matrix from vector
a <- c(1,2,3,4)
A <- matrix(a, nrow = 2)
A

# row-major order
A <- matrix(1:4, nrow = 2, byrow = T)
A

# Ways to get dimensions
dim(A)
nrow(A)
ncol(A)

# Indexing a matrix
A[1,1]
A[,1] # Gets first column
A[1,] # Gets first row

# Conditional matrix indexing
lr <- c(TRUE, FALSE, TRUE)
A[lr, ]

diag(A) # gets diagonal elements
diag(A) <- 0 # You can also set diagonal elements

# The +, -, *, / symbols work in an element-wise fashion.
# Use %*% for matrix multiplication.

t(A) # Transposes the matrix

solve(A) # Finds the inverse

A %*% solve(A) # will always equal the Identity matrix