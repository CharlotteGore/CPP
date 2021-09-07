add_subdirectory(doctest)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/doctest/scripts/cmake")

add_executable(CodeKataTest TestMain.cpp CodeKataTest.cpp 0-0.txt 1-0.txt)
target_link_libraries(CodeKataTest PUBLIC CodeKata)
target_link_libraries(CodeKataTest PUBLIC doctest::doctest)

include(doctest)
doctest_discover_tests(CodeKataTest ADD_LABELS 1)
