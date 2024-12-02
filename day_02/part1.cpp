#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::istringstream readFileToStringStream() {
  std::fstream file("input");
  std::stringstream buffer;
  buffer << file.rdbuf();
  return std::istringstream(buffer.str());
}

bool isValidDifference(int a, int b) {
  int diff = std::abs(a - b);
  return diff >= 1 && diff <= 3;
}

bool isSafe(const std::vector<int> &vec) {
  bool ascending = true;
  bool descending = true;

  for (size_t i = 1; i < vec.size(); ++i) {
    if (vec[i] < vec[i - 1] || !isValidDifference(vec[i], vec[i - 1])) {
      ascending = false;
    }
    if (vec[i] > vec[i - 1] || !isValidDifference(vec[i], vec[i - 1])) {
      descending = false;
    }
  }

  return ascending || descending;
}

std::vector<int> parseLine(const std::string &line) {
  std::vector<int> result;
  std::stringstream ss(line);
  int number;
  while (ss >> number) {
    result.push_back(number);
  }
  return result;
}

int main() {
  int safe = 0;
  std::istringstream stream = readFileToStringStream();

  // Here comes the stream reading
  std::vector<std::string> reports;
  std::string report;
  while (std::getline(stream, report)) {
    reports.push_back(report);
  }

  // Here comes the logic
  for (const auto &report : reports) {
    std::vector<int> levels = parseLine(report);
    if (isSafe(levels)) {
      safe++;
    }
  }

  std::cout << safe << std::endl;

  return 0;
}