#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;

#define TEST_TEXT_FILES_HOME    "test_txt/"







TEST_GROUP(readInput)
{

};


TEST(readInput, SingleNewlineReturnsEmptyString)
{
    std::ifstream testInputFile(TEST_TEXT_FILES_HOME"single_newline.txt", std::ifstream::in);

    std::string result = readInput(testInputFile);

    testInputFile.close();

    CHECK(result.empty());
}


TEST(readInput, CopiesWhatWasRead)
{
    std::ifstream testInputFile(TEST_TEXT_FILES_HOME"test_input.txt", std::ifstream::in);

    std::string result = readInput(testInputFile);

    testInputFile.close();

    CHECK(result.compare("hello") == 0);
}


TEST(readInput, OverwritesNonEmptyStringBuffer)
{
    std::ifstream testInputFile(TEST_TEXT_FILES_HOME"test_input.txt", std::ifstream::in);

    std::string result("This is a non-empty string.");
    CHECK_FALSE(result.empty());

    result = readInput(testInputFile);

    testInputFile.close();

    CHECK(result.compare("hello") == 0);
}


TEST(readInput, ContinuesAfterTheNewline)
{
    std::ifstream testInputFile(TEST_TEXT_FILES_HOME"test_input_multiple_lines.txt", std::ifstream::in);

    std::string result;

    result = readInput(testInputFile);

    CHECK(result.compare("first") == 0);

    result = readInput(testInputFile);

    CHECK(result.compare("second") == 0);

    result = readInput(testInputFile);

    CHECK(result.compare("third") == 0);

    result = readInput(testInputFile);

    CHECK(result.compare("fourth") == 0);

    result = readInput(testInputFile);

    CHECK(result.compare("fifth") == 0);

    testInputFile.close();
}


TEST(readInput, ReadsSpaces)
{
    std::ifstream testInputFile(TEST_TEXT_FILES_HOME"test_input_spaces.txt", std::ifstream::in);
    CHECK(testInputFile.is_open());
    CHECK(testInputFile.good());

    std::string result;

    result = readInput(testInputFile);

    CHECK(result.compare("first second") == 0);

    result = readInput(testInputFile);

    CHECK(result.compare("moe larry curly") == 0);

    result = readInput(testInputFile);

    CHECK(result.compare("fi phi pho fum") == 0);

    testInputFile.close();
}
