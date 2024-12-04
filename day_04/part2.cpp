#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::string inputFile = "./input";

bool isValidPosition(int x, int y, int maxX, int maxY) {
  return x >= 0 && x < maxX && y >= 0 && y < maxY;
}

bool isValidXMAS(const std::vector<std::string> &grid, int i, int j) {
  return ((grid[i][j] == 'M' && grid[i + 2][j + 2] == 'S') ||
          (grid[i][j] == 'S' && grid[i + 2][j + 2] == 'M')) &&
         ((grid[i + 2][j] == 'M' && grid[i][j + 2] == 'S') ||
          (grid[i + 2][j] == 'S' && grid[i][j + 2] == 'M'));
}

int countXMASOccurrences(const std::vector<std::string> &grid) {
  int count = 0;
  int maxX = grid.size();
  int maxY = grid[0].size();

  /*
  ...     M..    ..M     ..S     S..
  .A. && (... || ...  || ...  || ...)
  ...     ..S    S..     M..     ..M
  */
  for (int i = 0; i <= maxX - 3; ++i) {
    for (int j = 0; j <= maxY - 3; ++j) {
      if (grid[i + 1][j + 1] == 'A' && isValidXMAS(grid, i, j)) {
        ++count;
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

  result = countXMASOccurrences(grid);

  std::cout << result << std::endl;

  return 0;
}