#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

const std::string inputFile = "./input";

int main() {

  std::ifstream file(inputFile);
  if (!file) {
    std::cerr << "Error opening file" << std::endl;
    return 1;
  }
  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  std::regex pattern(R"(mul\(\d+,\d+\)|do\(\)|don't\(\))");
  std::sregex_iterator it(fileContent.begin(), fileContent.end(), pattern);
  std::sregex_iterator end;

  std::vector<std::string> matches;
  for (; it != end; ++it) {
    matches.push_back(it->str());
  }

  int result = 0;
  bool mulEnabled = true;
  for (const auto &match : matches) {
    if (match == "do()") {
      mulEnabled = true;
    } else if (match == "don't()") {
      mulEnabled = false;
    } else if (mulEnabled && match.find("mul(") == 0) {
      size_t commaPos = match.find(',');
      std::string a = match.substr(4, commaPos - 4);
      std::string b = match.substr(commaPos + 1, match.size() - commaPos - 2);
      result += std::stoi(a) * std::stoi(b);
    }
  }

  std::cout << result << std::endl;

  return 0;
}