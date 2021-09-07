//
// Created by Joakim Nohlgård on 2020-02-20.
//

#include "CodeKata.h"
#include "doctest/doctest.h"

// Start here:
// https://github.com/onqtam/doctest/blob/master/doc/markdown/tutorial.md

TEST_CASE("A file with 6 lines and one single line comment has 5 lines") {
  CHECK(kata::count_lines_from_file("6-1.txt") == 5);
}

TEST_CASE("Doesn't ignore content before single line comment") {
  CHECK(kata::count_lines_from_file("6-1-alt.txt") == 6);
}

TEST_CASE("Doesn't count multiline comments") {
  CHECK(kata::count_lines_from_file("testcase1.txt") == 3);
}

TEST_CASE("is not fooled comment openers in strings") {
  CHECK(kata::count_lines_from_file("testcase2.txt") == 5);
}
