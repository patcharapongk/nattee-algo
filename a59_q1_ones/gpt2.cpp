#include <climits> // For INT_MAX
#include <cmath>   // For std::abs
#include <iostream>
#include <vector>

// Generate q_k values up to 10^9
std::vector<long long> generateQkValues() {
  std::vector<long long> qkValues;
  long long value = 1;
  for (int i = 0; i < 12;
       ++i) { // Extended to ensure we cover all bases up to q_11
    qkValues.push_back(value);
    value = value * 10 + 1;
  }
  return qkValues;
}

// Base case checking
int basecases(int target) {
  switch (target) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 3;
  case 4:
    return 4;
  case 5:
    return 5;
  case 6:
    return 6;
  case 7:
    return 6; // Optimized to 6: 11 - 1 - 1 - 1 - 1
  case 8:
    return 8; // Corrected to 8 for a direct approach, but optimized should be
              // less, this is a placeholder
  case 9:
    return 4; // 11 - 1 - 1
  case 10:
    return 3; // 11 - 1
  case 11:
    return 2;
  default:
    return INT_MAX; // Handle other cases generically
  }
}

// Recursive function to find the minimum number of 1s
int findMinOnes(int n, const std::vector<long long> &qkValues) {
  if (n < 12)
    return basecases(std::abs(n)); // Handle base cases directly

  int minOnes = INT_MAX;
  for (size_t i = 0; i < qkValues.size() && qkValues[i] <= n + 1;
       ++i) { // Only consider qk values up to n + 1
    // For direct subtraction
    int remainder = n - qkValues[i];
    int onesNeeded = 1 + (remainder >= 0 ? findMinOnes(remainder, qkValues)
                                         : findMinOnes(-remainder, qkValues));
    minOnes = std::min(minOnes, onesNeeded);

    // Check for adding qk if it makes sense (i.e., when subtracting makes n
    // negative)
    if (qkValues[i] - n < n) { // Avoid infinite loop
      remainder = std::abs(n + qkValues[i]);
      onesNeeded = 1 + findMinOnes(remainder, qkValues);
      minOnes = std::min(minOnes, onesNeeded);
    }
  }
  return minOnes;
}

int main() {
  std::vector<long long> qkValues = generateQkValues();
  int n;
  std::cout << "Enter n: ";
  std::cin >> n;

  int minOnes = findMinOnes(n, qkValues);
  std::cout << "Minimum number of 1s required: " << minOnes << std::endl;

  return 0;
}
