# Comments use a hashtag
# Recommend assigning variables using <- rather than =

a <- 10 # By default this is double, if you want an integer write 10L

X <- matrix(1,10,2)
View(X) # Inspect a matrix in a spreadsheet type window

rm(a) # removes a variable from the environment

typeof(X) # shows data type of variable

# %% modular arithmetic
10%%3

# %/% integer division
10%/%3

# Standard division
10/3

# ^ Exponentiation
2^10 # 2 to the 10th power

vec1 <- c(1, 2, 3, 4) # This is a vector. Note that vectors are ONE-INDEXED.
vec2 <- c(5, 6, 7, 8)

vec3 <- c(vec1, vec2) # 1, 2,...,8

for (i in 1:10){
  # i takes 1 in the first iteration,
  # i takes 2 in the second iteration ...
  print(i)
}

a <- 1:10 # a takes all values between 1 and 10
vec3[4:6] # gets 4th 5th 6th elements

for (i in letters[1:3]){
  cat(i) # print compactly
}

paste("a", "b")

# Functions
smaller_than_10 <- function(n){
  if(n<10){
    return(TRUE)
  }else{
    return(FALSE)
  }
}