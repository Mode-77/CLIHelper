/*
    File:   cli.hpp
    Author: Jared Thomas
    Date:   Thursday, December 2, 2021
*/


#ifndef CLI_HPP
#define CLI_HPP


#include <istream>
#include <string>


//Extracts the contents of inputStream up to, but excluding the newline
//character and stores them in inputString.
//
//Original contents of inputString are lost.
void readInput(std::istream &inputStream, std::string &inputString);/**/

void stripLeadingSpaces(std::string &input);//exclude

void grabUntilSpace(std::string &input);//exclude

void grabFromSpace(std::string &input);//exclude

void chop(const std::string &piece, std::string &whole);//exclude

//Returns the number of fields in the line
int fieldCount(const std::string &input);/**/

//Stores the field at index in result.
//
//Original contents of result are lost.
void extractField(/**/
    const std::string &input,
    const size_t index,
    std::string &result);

//Returns true if the field at index matches the key,
//returns false otherwise
bool fieldIs(const char *key, const size_t fieldNumber, const char *fields);/**/

//Returns true if there are no fields in the line, returns false otherwise
bool allFieldsEmpty(const std::string &fields);/**/



#endif
