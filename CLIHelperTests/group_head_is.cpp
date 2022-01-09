#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;








TEST_GROUP(HeadIs)
{

};

TEST(HeadIs, Returns_true_if_head_matches_key)
{
    CHECK_EQUAL(false, headIs("key", "ham"));
    CHECK_EQUAL(true, headIs("key", "key"));
    CHECK_EQUAL(true, headIs("key", "key ham"));
    CHECK_EQUAL(false, headIs("key", "green eggs and ham"));
}
