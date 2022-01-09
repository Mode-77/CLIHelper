/*
    File:   cli.cpp
    Author: Jared Thomas
    Date:   Thursday, December 2, 2021
*/

#include "cli.hpp"

#include <istream>
#include <string>
#include <vector>
#include <cstddef>
#include <cassert>
#include <cstring>


using std::string;






/* Internal functions *********************************************************/



///Captures the substring beginning at the first non-space character and ending
///at the end of the string.
///
///The result is stored back in the input string.
static void stripLeadingSpaces(string &input)
{
    const size_t positionOfFirstNonSpace = input.find_first_not_of(" ");
    if(positionOfFirstNonSpace == string::npos) {
        input.clear(); //input is all spaces or empty; return the empty string.
        return;
    }
    input = input.substr(positionOfFirstNonSpace);
}


///Captures the substring beginning at the first character and ending at the
///first character that is not a space.
///
///The result is stored back in the input string.
static void grabUntilSpace(string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == 0) {
        input.clear(); //The first character is space; return the empty string.
        return;
    }
    if(positionOfNextSpace == string::npos)
        return; //No spaces in input or empty; leave input unchanged.

    input = input.substr(0, positionOfNextSpace);
}


///Captures the substring beginning at the first space and ending at the end
///of the string.
///The result is stored back in the input string.
static void grabFromSpace(string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == string::npos) {
        input.clear(); //No spaces in input or empty; return the empty string.
        return;
    }
    input = input.substr(positionOfNextSpace);
}






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




/* End internal functions *****************************************************/



string readInput(std::istream &stream)
{
    string buffer;
    std::getline(stream, buffer);
    return buffer;
}


unsigned int fieldCount(const string &input)
{
    unsigned int fieldsCounted = 0;

    string remainder(input);
    stripLeadingSpaces(remainder);
    while(!remainder.empty()) {
        grabFromSpace(remainder);
        stripLeadingSpaces(remainder);
        fieldsCounted++;
    }
    return fieldsCounted;
}


// allFieldsEmpty(line) == false
unsigned int argumentCount(const string &line)
{
    //Arguments are any fields after the first
    return fieldCount(line) - 1;
}


bool allFieldsEmpty(const string &fields)
{
    return fieldCount(fields) == 0;
}


// fieldCount(line) > 0
// 0 <= fieldNumber < fieldCount(line)
bool fieldIs(const string &key, const size_t fieldNumber, const string &line)
{
    string result = grabField(fieldNumber, line);
    return result.compare(key) == 0;
}


// fieldCount(line) > 0
bool headIs(const string &key, const string &line)
{
    return fieldIs(key, 0, line);
}


// argumentCount(line) > 0
bool argumentIs(const string &key, const size_t N, const string &line)
{
    return fieldIs(key, 1 + N, line);
}


// fieldCount(line) > 0
// 0 <= index < fieldCount(line)
string grabField(const size_t index, const string &line)
{
    string remainder(line);
    stripLeadingSpaces(remainder);

    if(index == 0) {
        grabUntilSpace(remainder);
        return remainder;
    }

    grabFromSpace(remainder);
    return grabField(index - 1, remainder);
}


// allFieldsEmpty(line) == false
bool noArguments(const string &line)
{
    return argumentCount(line) == 0;
}


// noArguments(line) == false
string grabArgument(const size_t N, const string &line)
{
    return grabField(1 + N, line);
}
