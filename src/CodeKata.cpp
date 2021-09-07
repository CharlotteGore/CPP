//
// Created by Joakim Nohlgård on 2020-02-20.
//

#include "CodeKata.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

namespace kata {

int count_lines_from_file(const std::string &filename) {
  std::ifstream input;
  input.open(filename);
  if (!input) {
    std::cerr << "Unable to open file";
    exit(1);
  } else {
    std::cout << "File opened";
  }
  int numLines = 0;
  auto inCommentBlock = false;
  std::string line;
  while (std::getline(input, line)) {
    auto codeFound = false;
    auto inString = false;
    for (size_t i = 0; i < line.length(); i++) {
      // we not currently in a block
      if (!inCommentBlock) {
        // check for strings
        if (!inString && line[i] == '"') {
          inString = true;
        } else if (inString && line[i] == '"') {
          inString = false;
        } else if (!inString) {
          // otherwise let's check for comment openers
          if (line[i] == '/' && line[i + 1] == '/') {
            // single line comment found, ignore the rest of the line
            break;
          } else if (line[i] == '/' && line[i + 1] == '*') {
            inCommentBlock = true;
            i++;
          } else if (!std::isspace(line[i])) {
            codeFound = true;
          }
        }
      } else {
        if (line[i] == '*' && line[i + 1] == '/') {
          i++;
          inCommentBlock = false;
        }
      }
    }

    if (codeFound) {
      std::cout << line << '\n';
      ++numLines;
    }
  }
  return numLines;
}
}  // namespace kata
