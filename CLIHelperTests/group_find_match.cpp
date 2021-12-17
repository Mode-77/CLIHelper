#include "CppUTest/TestHarness.h"

#include "../cli.hpp"









TEST_GROUP(findMatch)
{
    const char *RAINBOW_COLORS[8] = {
        "red",
        "orange",
        "yellow",
        "green",
        "blue",
        "indigo",
        "violet",
        nullptr
    };
};


TEST(findMatch, Returns_Index_If_Match_Is_Found)
{
    CHECK_EQUAL(5, findMatch("indigo", RAINBOW_COLORS));
    CHECK_EQUAL(2, findMatch("yellow", RAINBOW_COLORS));
}


TEST(findMatch, Returns_Negative_One_If_No_Match_Found)
{
    CHECK_EQUAL(-1, findMatch("eggs", RAINBOW_COLORS));
}
