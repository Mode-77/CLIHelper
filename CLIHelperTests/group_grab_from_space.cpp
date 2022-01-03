#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;





static void grabFromSpace(std::string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == std::string::npos) {
        input.clear(); //No spaces in input or empty; return the empty string.
        return;
    }
    input = input.substr(positionOfNextSpace);
}




TEST_GROUP(grabFromSpace)
{

};

TEST(grabFromSpace, Leaves_An_Empty_String_Unchanged)
{
    string testInput("");
    grabFromSpace(testInput);
    CHECK_EQUAL("", testInput);
}

TEST(grabFromSpace, Captures_All_From_Space_And_Beyond)
{
    vector<string> testCases {
        "a"             ,"",
        "spam "         ," ",
        "be  "          ,"  ",
        "bat be spam a" ," be spam a",
        "     "         ,"     "
    };

    for(size_t i = 0; i < testCases.size(); i += 2) {
        string thisCase(testCases.at(i));
        grabFromSpace(thisCase);
        CHECK_EQUAL(testCases.at(i + 1), thisCase);
    }
}
