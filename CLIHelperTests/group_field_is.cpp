#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;








TEST_GROUP(fieldIs)
{

};


TEST(fieldIs, Returns_True_If_Nth_Field_Is_X)
{
    CHECK_EQUAL(1, fieldIs("c", 2, "a b c d"));
    CHECK_EQUAL(1, fieldIs("a", 0, "a b c d"));
    CHECK_EQUAL(1, fieldIs("d", 3, "a b c d"));
    CHECK_EQUAL(1, fieldIs("b", 1, "a b c d"));
}
