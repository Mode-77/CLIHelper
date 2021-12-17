#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;








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
