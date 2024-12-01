#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
  int result = 0;

  std::fstream file("./input");

  std::stringstream buffer;
  buffer << file.rdbuf();
  std::istringstream stream(buffer.str());

  // Here comes the stream reading

  // Here comes the logic

  std::cout << result << std::endl;

  return 0;
}