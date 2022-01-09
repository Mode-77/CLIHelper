#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;








TEST_GROUP(ArgumentIs)
{

};

TEST(ArgumentIs, Returns_true_if_Nth_argument_is_key)
{
    CHECK_EQUAL(false, argumentIs("a", 0, "a b"));
    CHECK_EQUAL(true, argumentIs("b", 0, "a b"));
    CHECK_EQUAL(true, argumentIs("d", 2, "a b c d"));
}
