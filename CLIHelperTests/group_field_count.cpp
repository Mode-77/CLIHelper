#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;

#define TEST_TEXT_FILES_HOME    "test_txt/"




struct TestCheck {
    string given;
    int expect;
};





void runTestCheck(struct TestCheck &check)
{
    CHECK_EQUAL(check.expect, fieldCount(check.given));
}



void runSeriesCheck(vector<struct TestCheck> &checkList)
{
    for(size_t i = 0; i < checkList.size(); i++) {
        runTestCheck(checkList.at(i));
    }
}





TEST_GROUP(fieldCount)
{

};


TEST(fieldCount, Returns_Zero_When_Given_An_Empty_String)
{
    CHECK_EQUAL(0, fieldCount(""));
}


TEST(fieldCount, Returns_One_When_Given_A_String_With_Length_One)
{
    CHECK_EQUAL(1, fieldCount("a"));
}


TEST(fieldCount, Returns_Zero_When_Given_Strings_With_No_Fields)
{
    vector<struct TestCheck> checks {
        {" "                               , 0},
        {"                "                , 0},
        {"                                ", 0}
    };

    runSeriesCheck(checks);
}


TEST(fieldCount, Ignores_Leading_Spaces)
{
    vector<struct TestCheck> checks {
        {" t"  , 1},
        {"  t" , 1},
        {"   t", 1}
    };

    runSeriesCheck(checks);
}


TEST(fieldCount, Ignores_Trailing_Spaces)
{
    vector<struct TestCheck> checks {
        {"t "  , 1},
        {"t  " , 1},
        {"t   ", 1}
    };

    runSeriesCheck(checks);
}


TEST(fieldCount, Counts_Multiple_Fields)
{
    vector<struct TestCheck> checks {
        {"a b", 2},
        {"a b c", 3},
        {"spam eggs ham", 3},
        {" dog fish cat ", 3},
        {" red  orange   yellow    green     blue", 5},
        {"!, @#, $%^, &*()", 4}
    };

    runSeriesCheck(checks);
}
