#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;




// input is not the empty string.
static void grabUntilSpace(string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == 0) {
        input = "";
        return;
    }
    if(positionOfNextSpace == string::npos)
        return;

    const size_t lengthOfSubstring = positionOfNextSpace;

    input = input.substr(0, lengthOfSubstring);
}




TEST_GROUP(grabUntilSpace)
{

};


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
