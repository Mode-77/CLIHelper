#include "CppUTest/TestHarness.h"

#include "../cli.hpp"

#include <string>
#include <vector>
#include <cassert>

using std::string;
using std::vector;



// piece is a substring of whole.
// piece will be found at index 0.
static void chop(const string &piece, string &whole)
{
    if(piece.empty())
        return;
    const size_t positionOfStart = whole.find(piece);

    assert(positionOfStart == 0);

    const size_t chopStart = positionOfStart + piece.length();
    whole = whole.substr(chopStart);
}



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
