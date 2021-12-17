#include "CppUTest/TestHarness.h"

#include "../cli.hpp"








TEST_GROUP(allFieldsEmpty)
{

};


TEST(allFieldsEmpty, Returns_False_If_String_Contains_Fields)
{
    CHECK_EQUAL(false, allFieldsEmpty("a b c d"));
}


TEST(allFieldsEmpty, Returns_True_If_String_Contains_No_Fields)
{
    CHECK_EQUAL(true, allFieldsEmpty(""));
    CHECK_EQUAL(true, allFieldsEmpty(" "));
    CHECK_EQUAL(true, allFieldsEmpty("  "));
}
