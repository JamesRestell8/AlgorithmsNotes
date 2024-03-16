dist <- function(a, b)
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

angle <- function(a, b)
{
  if (length(a) != length(b))
  {
    print("Incompatible vector sizes!")
    return()
  }
  cosUsingDotProd <- sum(a*b) / (sqrt(sum(a^2)) * sqrt(sum(b^2)))
  angle <- acos(cosUsingDotProd)
  degreesConverted <- angle * (180 / pi)
  
  return(degreesConverted)
}

vectorInfo <- function(x)
{
  steps = matrix(c(seq(0, 0, length.out=length(x))), nrow=6, ncol=2)
  currentLoc = c(0,0)
  for (i in 1:nrow(x))
  {
    steps[i, 1] = x[i, 1] - currentLoc[1]
    steps[i, 2] = x[i, 2] - currentLoc[2]
    currentLoc = x[i,]
  }
  lengths = c(seq(0,0,length.out=nrow(steps) - 1))
  directions = c(seq(0,0,length.out=nrow(steps) - 1))
  for (i in 2:nrow(steps))
  {
    lengths[i-1] <- dist(steps[i,], c(0,0))
    directions[i-1] <- angle(steps[i,], c(1,0))
    arrows(x[i-1, 1], x[i-1, 2], x[i, 1], x[i, 2])
  }
  
  return( list(lengths, directions, sum(lengths)) )
}

locs <- matrix(c(0, 2, 3, 2, 1, 1,
                 0, 1, 1, 3, 4, 5), 6, 2)
plot(locs)
vectorInfo(locs)
