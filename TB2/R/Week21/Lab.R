getEuclideanDistanceVectorized <- function(a, b)
{
  distance = 0
  if (length(a) != length(b))
  {
    print("Incompatible vector sizes!")
    return()
  }
  distance = distance + sqrt(sum((a - b)^2))
  return(distance)
}

getEuclideanDistance <- function(a, b)
{
  sumSquares = 0
  for (i in 1:length(a))
  {
    sumSquares = sumSquares + (a[i] - b[i])^2
  }
  return(sqrt(sumSquares))
}

pdist1 <- function(A, B)
{
  D = matrix(seq(0, 0, length.out=nrow(A)*ncol(B)), nrow(A), ncol(B))
  for (i in 1:nrow(A))
  {
    for (j in 1:ncol(B))
    {
      D[i, j] <- getEuclideanDistance(A[i,], B[,j])
    }
  }
  return(D)
}

pdist2 <- function(A, B)
{
  D = matrix(seq(0, 0, length.out=nrow(A)*ncol(B)), nrow(A), ncol(B))
  for (i in 1:nrow(A))
  {
    for (j in 1:ncol(B))
    {
      D[i, j] <- getEuclideanDistanceVectorized(A[i,], B[,j])
    }
  }
  return(D)
}

### For some reason I can't figure out how to do pdist3 but I'm pretty
### sure I can do pdist4...

pdist4 <- function(A, B)
{
  a <- rowSums(A^2)
  b <- colSums(B^2)
  oneA <- matrix(seq(1, 1, length.out=nrow(A)), nrow(A), 1)
  oneB <- matrix(seq(1, 1, length.out=ncol(B)), ncol(B), 1)
  
  D <- sqrt((a %*% t(oneB)) + (oneA %*% t(b)) - (2*(A%*%B)))
  return(D)
}

vectorA <- matrix(rnorm(500*784, 0, 1), 500, 784)
vectorB <- matrix(rnorm(784*800, 0, 1), 784, 800)

print("3 for loops...")
tic <- Sys.time()
a <- pdist1(vectorA, vectorB)
Sys.time() - tic

print("2 for loops...")
tic <- Sys.time()
a <- pdist2(vectorA, vectorB)
Sys.time() - tic

print("0 for loops...")
tic <- Sys.time()
a <- pdist4(vectorA, vectorB)
Sys.time() - tic


