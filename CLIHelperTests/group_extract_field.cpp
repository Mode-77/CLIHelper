#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;

#define TEST_TEXT_FILES_HOME    "test_txt/"







TEST_GROUP(extractField)
{

};


TEST(extractField, Returns_Nth_Field)
{
    const string testInput(" abe  bat   spamhouse    action  ");


    vector<string> expected {
        "abe",
        "bat",
        "spamhouse",
        "action"
    };

    string result;

    for(size_t i = 0; i < expected.size(); i++) {

        extractField(testInput, i, result);

        CHECK_EQUAL(expected.at(i), result);
    }
}
