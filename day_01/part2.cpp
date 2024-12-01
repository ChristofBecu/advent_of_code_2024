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

  int simmilarity = 0;
  std::vector<int> simmilarities;

  for (int i = 0; i < leftNumbers.size(); i++) {
    int leftNumber = leftNumbers[i];

    int count =
        std::count(rightNumbers.begin(), rightNumbers.end(), leftNumber);

    simmilarity = leftNumber * count;

    simmilarities.push_back(simmilarity);
  }

  long sum = 0;
  for (int i = 0; i < simmilarities.size(); i++) {
    sum += simmilarities[i];
  }

  std::cout << sum << std::endl; // 22545250

  return 0;
}