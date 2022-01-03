#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;

#define TEST_TEXT_FILES_HOME    "test_txt/"



static void stripLeadingSpaces(string &input)
{
    const size_t positionOfFirstNonSpace = input.find_first_not_of(" ");
    if(positionOfFirstNonSpace == string::npos) {
        input.clear();
        return;
    }
    input = input.substr(positionOfFirstNonSpace);
}





TEST_GROUP(stripLeadingSpaces)
{

};


TEST(stripLeadingSpaces, Leaves_An_Empty_String_Unchanged)
{
    string testInput("");
    stripLeadingSpaces(testInput);
    CHECK_EQUAL("", testInput);
}


TEST(stripLeadingSpaces, Strips_String_With_All_Spaces)
{
    vector<string> testCases {
        " ",
        "  ",
        "   "
    };

    for(size_t i = 0; i < testCases.size(); i++) {
        string thisCase(testCases.at(i));
        stripLeadingSpaces(thisCase);
        CHECK_EQUAL("", thisCase);
    }
}


TEST(stripLeadingSpaces, Leaves_Strings_With_No_Leading_Spaces_Unchanged)
{
    vector<string> testCases {
        "a",
        "spam",
        "be",
        "bat"
    };

    for(size_t i = 0; i < testCases.size(); i++) {
        string thisCase(testCases.at(i));
        stripLeadingSpaces(thisCase);
        CHECK_EQUAL(testCases.at(i), thisCase);
    }
}


TEST(stripLeadingSpaces, Strips_Leading_Spaces)
{
    vector<string> testCases {
        " a"            , "a",
        "  spam"        , "spam",
        "be "           , "be ",
        " bat "         , "bat "
    };

    for(size_t i = 0; i < testCases.size(); i += 2) {
        string thisCase(testCases.at(i));
        stripLeadingSpaces(thisCase);
        CHECK_EQUAL(testCases.at(i + 1), thisCase);
    }
}
