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
using std::vector;













void stripLeadingSpaces(string &input)
{
    const size_t positionOfFirstNonSpace = input.find_first_not_of(" ");
    if(positionOfFirstNonSpace == string::npos) {
        input.clear();
        return;
    }
    input = input.substr(positionOfFirstNonSpace);
}



// input is not the empty string.
void grabUntilSpace(string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == 0) {
        input = "";
        return;
    }
    if(positionOfNextSpace == string::npos)
        return;

    const size_t lengthOfSubstring = positionOfNextSpace;

    input = input.substr(0, lengthOfSubstring);
}



// input is not the empty string.
void grabFromSpace(string &input)
{
    const size_t positionOfNextSpace = input.find_first_of(" ");
    if(positionOfNextSpace == string::npos) {
        input = "";
        return;
    }

    input = input.substr(positionOfNextSpace);
}






// piece is a substring of whole.
// piece will be found at index 0.
void chop(const string &piece, string &whole)
{
    if(piece.empty())
        return;
    const size_t positionOfStart = whole.find(piece);

    assert(positionOfStart == 0);

    const size_t chopStart = positionOfStart + piece.length();
    whole = whole.substr(chopStart);
}



int fieldCount(const string &input)
{
    int fieldsCounted = 0;

    // size_t positionOfFirstNonSpace;
    // size_t positionOfNextSpace;

    // positionOfFirstNonSpace = input.find_first_not_of(" ");
    // while(positionOfFirstNonSpace != string::npos) {
    //     fieldsCounted++;
    //     positionOfNextSpace = input.find_first_of(" ", positionOfFirstNonSpace);
    //     positionOfFirstNonSpace = input.find_first_not_of(" ", positionOfNextSpace);
    // }

    // return fieldsCounted;

    string remainder(input);            // Make a copy
    stripLeadingSpaces(remainder);
    while(!remainder.empty()) {
        grabFromSpace(remainder);
        stripLeadingSpaces(remainder);
        fieldsCounted++;
    }
    return fieldsCounted;
}



// fieldCount(input) > 0
// 0 <= index < fieldCount(input)
void extractField(
    const string &input,
    const size_t index,
    string &result)
{
    // size_t fieldsCounted = 0;

    // string remainder(input);
    // stripLeadingSpaces(remainder);
    // while(!remainder.empty()) {
    //     string foundField(remainder);
    //     grabUntilSpace(foundField);
    //     fieldsCounted++;
    //     if(fieldsCounted > index) {
    //         result = foundField;
    //         return;
    //     }
    //     chop(foundField, remainder);
    //     stripLeadingSpaces(remainder);
    // }

    string remainder(input);
    stripLeadingSpaces(remainder);

    if(index == 0) {
        grabUntilSpace(remainder);
        result = remainder;
        return;
    }

    grabFromSpace(remainder);
    extractField(remainder, index - 1, result);
}



void readInput(std::istream &inputStream, std::string &inputString)
{
    std::getline(inputStream, inputString);
}









// fieldCount(fields) > 0
// 0 <= fieldNumber < fieldCount(fields)
int fieldIs(const char *key, const size_t fieldNumber, const char *fields)
{
    string temp(fields);    // Stringify
    string result;
    extractField(temp, fieldNumber, result);
    return result.compare(key) == 0;
}


bool allFieldsEmpty(const string &fields)
{
    return fieldCount(fields) == 0;
}

/*
int FindMatch(const char* buffer, const char* list[], unsigned length)
{
    for (unsigned i = 0; i < length; i++) {
        if (!strcmp(buffer, list[i])) {
            return i;
        }
    }
    return -1;
}
*/




// list shall be terminated with a null pointer
int findMatch(const char *key, const char *list[])
{
    for(size_t i = 0; list[i] != nullptr; i++) {
        if(!strcmp(key, list[i]))
            return i;
    }
    return -1;
}
