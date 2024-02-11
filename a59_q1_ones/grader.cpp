#include <stdio.h>
#include <stdlib.h>

// Pre-defined array of numbers consisting only of the digit '1'
int addends[] = {1,      11,      111,      1111,      11111,
                 111111, 1111111, 11111111, 111111111, 1111111111};

// Recursive function to find the minimum number of digits '1' required
int findMinOnes(int sum, int depth, int count) {
  // Base case: If the sum has been reduced to 0
  if (sum == 0)
    return count;

  // If no more addends are available to use
  if (depth <= 0)
    return 1111111111; // Return a large number to indicate failure

  // Calculate the maximum number of times the current addend can be used
  int lower = sum / addends[depth - 1];
  // Adjust by one to explore both less and more usage of the current addend
  int upper = sum >= 0 ? lower + 1 : lower - 1;

  // Recurse with the sum adjusted by using the addend 'lower' and 'upper' times
  int countLower = findMinOnes(sum - lower * addends[depth - 1], depth - 1,
                               count + abs(lower) * depth);
  int countUpper = findMinOnes(sum - upper * addends[depth - 1], depth - 1,
                               count + abs(upper) * depth);

  // Return the smaller of the two counts
  return countLower < countUpper ? countLower : countUpper;
}

int main() {
  int targetNumber;
  scanf("%d", &targetNumber);

  int depth;
  for (depth = 0; targetNumber >= addends[depth]; ++depth)
    ; // Determine the depth based on the target number

  // Calculate and print the minimum number of 1s required
  printf("%d\n", findMinOnes(targetNumber, depth + 1, 0));
}
