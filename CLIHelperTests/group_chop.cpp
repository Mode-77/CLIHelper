#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;








TEST_GROUP(chop)
{

};


TEST(chop, Removes_First_Substring_From_The_String)
{
    vector<string> testCases {
        "piece"       , "piecewhole"    , "whole" ,
        "trip "       , "trip you up"   , "you up",
        " bat"        , " bathouse"     , "house" ,
        " action "    , " action movie ", "movie ",
        "hello, world", "hello, world"  , ""      ,
        ""            , "hello, world"  , "hello, world"
    };

    for(size_t i = 0; i < testCases.size(); i += 3) {
        string piece(testCases.at(i));
        string whole(testCases.at(i + 1));
        chop(piece, whole);
        CHECK_EQUAL(testCases.at(i + 2), whole);
    }
}
