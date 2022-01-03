#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;





static void grabUntilSpace(std::string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == 0) {
        input.clear(); //The first character is space; return the empty string.
        return;
    }
    if(positionOfNextSpace == std::string::npos)
        return; //No spaces in input or empty; leave input unchanged.

    input = input.substr(0, positionOfNextSpace);
}




TEST_GROUP(grabUntilSpace)
{

};

TEST(grabUntilSpace, Leaves_An_Empty_String_Unchanged)
{
    string testInput("");
    grabUntilSpace(testInput);
    CHECK_EQUAL("", testInput);
}

TEST(grabUntilSpace, Captures_All_Before_Space)
{
    vector<string> testCases {
        "a"             ,"a",
        "spam "         ,"spam",
        "be  "          ,"be",
        "bat be spam a" ,"bat",
        "     "         ,""
    };

    for(size_t i = 0; i < testCases.size(); i += 2) {
        string thisCase(testCases.at(i));
        grabUntilSpace(thisCase);
        CHECK_EQUAL(testCases.at(i + 1), thisCase);
    }
}
