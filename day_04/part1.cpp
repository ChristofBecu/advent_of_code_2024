#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

const std::string inputFile = "./input";

bool isValidPosition(int x, int y, int maxX, int maxY) {
  return x >= 0 && x < maxX && y >= 0 && y < maxY;
}

int countWordOccurrences(const std::vector<std::string> &grid,
                         const std::string &word) {
  std::vector<std::pair<int, int>> directions = {
      {0, 1},   // right
      {1, 0},   // down
      {1, 1},   // down-right
      {1, -1},  // down-left
      {0, -1},  // left
      {-1, 0},  // up
      {-1, -1}, // up-left
      {-1, 1}   // up-right
  };
  int wordLength = word.length();
  int count = 0;
  int maxX = grid.size();
  int maxY = grid[0].size();

  for (int i = 0; i < maxX; ++i) {
    for (int j = 0; j < maxY; ++j) {
      for (const auto &dir : directions) {
        bool found = true;
        for (int k = 0; k < wordLength; ++k) {
          int newX = i + k * dir.first;
          int newY = j + k * dir.second;
          if (!isValidPosition(newX, newY, maxX, maxY) ||
              grid[newX][newY] != word[k]) {
            found = false;
            break;
          }
        }
        if (found) {
          ++count;
        }
      }
    }
  }
  return count;
}

int main() {
  int result = 0;

  std::ifstream file(inputFile);
  if (!file) {
    std::cerr << "Error opening file" << std::endl;
    return 1;
  }

  std::vector<std::string> grid;
  std::string line;
  while (getline(file, line)) {
    grid.push_back(line);
  }

  std::string word = "XMAS";
  result = countWordOccurrences(grid, word);

  std::cout << result << std::endl;

  return 0;
}