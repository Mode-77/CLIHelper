#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;








TEST_GROUP(grabField)
{

};


TEST(grabField, Returns_Nth_Field)
{
    const string testInput(" abe  bat   spamhouse    action  ");

    vector<string> expected {
        "abe",
        "bat",
        "spamhouse",
        "action"
    };

    for(size_t i = 0; i < expected.size(); i++) {
        CHECK_EQUAL(expected.at(i), grabField(i, testInput));
    }
}
