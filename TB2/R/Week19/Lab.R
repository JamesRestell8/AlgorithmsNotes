getNumPrimes <- function(n)
{
  if (n < 2)
  {
    return(0)
  }
  numPrimes = 0
  for (num in 2:n)
  {
    if (prime(num))
    {
      numPrimes = numPrimes + 1
    }
  }
  return(numPrimes)
}

prime <- function(n)
{
  if (n < 2)
  {
    return(FALSE)
  }
  
  if (n == 2)
  {
    return(TRUE)
  }
  for (num in 2:(sqrt(n) + 1))
  {
    if (n%%num == 0)
    {
      return(FALSE)
    }
  }
  return(TRUE)
}

n=10000
start_time <- Sys.time()
print(getNumPrimes(n))
end_time <- Sys.time()

end_time - start_time

print("------Without Functions------")
start_time <- Sys.time()
numPrimes = 0
for (num in 2:n)
{
  if (prime(num))
  {
    numPrimes = numPrimes + 1
  }
}
numPrimes

end_time <- Sys.time()
end_time - start_time
