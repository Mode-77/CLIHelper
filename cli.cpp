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









/* Internal functions *********************************************************/




static void stripLeadingSpaces(std::string &input)
{
    const size_t positionOfFirstNonSpace = input.find_first_not_of(" ");
    if(positionOfFirstNonSpace == std::string::npos) {
        input.clear();
        return;
    }
    input = input.substr(positionOfFirstNonSpace);
}



// input is not the empty string.
static void grabUntilSpace(std::string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == 0) {
        input = "";
        return;
    }
    if(positionOfNextSpace == std::string::npos)
        return;

    const size_t lengthOfSubstring = positionOfNextSpace;

    input = input.substr(0, lengthOfSubstring);
}



// input is not the empty string.
static void grabFromSpace(std::string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == std::string::npos) {
        input.clear(); //No spaces in input or empty; return the empty string.
        return;
    }
    input = input.substr(positionOfNextSpace);
}






// piece is a substring of whole.
// piece will be found at index 0.
static void chop(const std::string &piece, std::string &whole)
{
    if(piece.empty())
        return;
    const size_t positionOfStart = whole.find(piece);

    assert(positionOfStart == 0);

    const size_t chopStart = positionOfStart + piece.length();
    whole = whole.substr(chopStart);
}




/* End internal functions *****************************************************/



void readInput(std::istream &inputStream, std::string &inputString)
{
    std::getline(inputStream, inputString);
}


unsigned int fieldCount(const std::string &input)
{
    unsigned int fieldsCounted = 0;

    std::string remainder(input);
    stripLeadingSpaces(remainder);
    while(!remainder.empty()) {
        grabFromSpace(remainder);
        stripLeadingSpaces(remainder);
        fieldsCounted++;
    }
    return fieldsCounted;
}


bool allFieldsEmpty(const std::string &fields)
{
    return fieldCount(fields) == 0;
}


// fieldCount(fields) > 0
// 0 <= fieldNumber < fieldCount(fields)
bool fieldIs(const char *key, const size_t fieldNumber, const char *fields)
{
    std::string temp(fields);    // Stringify
    std::string result;
    extractField(temp, fieldNumber, result);
    return result.compare(key) == 0;
}


// fieldCount(input) > 0
// 0 <= index < fieldCount(input)
void extractField(
    const std::string &input,
    const size_t index,
    std::string &result)
{
    std::string remainder(input);
    stripLeadingSpaces(remainder);

    if(index == 0) {
        grabUntilSpace(remainder);
        result = remainder;
        return;
    }

    grabFromSpace(remainder);
    extractField(remainder, index - 1, result);
}
