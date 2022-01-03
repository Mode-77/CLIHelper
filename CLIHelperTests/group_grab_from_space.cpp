#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;




// input is not the empty string.
static void grabFromSpace(string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == string::npos) {
        input = "";
        return;
    }

    input = input.substr(positionOfNextSpace);
}




TEST_GROUP(grabFromSpace)
{

};


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
