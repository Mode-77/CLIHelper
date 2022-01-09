#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;








TEST_GROUP(ArgumentCount)
{

};

TEST(ArgumentCount, Returns_the_correct_number_of_arguments)
{
    CHECK_EQUAL(0, argumentCount("ham"));
    CHECK_EQUAL(1, argumentCount("ham spam"));
    CHECK_EQUAL(2, argumentCount("ham spam eggs"));
    CHECK_EQUAL(3, argumentCount("ham spam eggs coffee"));
}
