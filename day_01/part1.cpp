#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
  std::vector<int> leftNumbers;
  std::vector<int> rightNumbers;

  std::fstream file("./input");

  std::stringstream buffer;
  buffer << file.rdbuf();
  std::istringstream stream(buffer.str());
  int left, right;

  while (stream >> left >> right) {
    leftNumbers.push_back(left);
    rightNumbers.push_back(right);
  }

  std::sort(leftNumbers.begin(), leftNumbers.end());
  std::sort(rightNumbers.begin(), rightNumbers.end());

  std::vector<int> distances;
  for (int i = 0; i < leftNumbers.size(); i++) {
    distances.push_back(abs(leftNumbers[i] - rightNumbers[i]));
  }

  int sum = 0;
  for (int i = 0; i < distances.size(); i++) {
    sum += distances[i];
  }

  std::cout << sum << std::endl; // 1222801

  return 0;
}