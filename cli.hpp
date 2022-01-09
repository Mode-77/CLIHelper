/*
    File:   cli.hpp
    Author: Jared Thomas
    Date:   Thursday, December 2, 2021
*/

#ifndef CLI_HPP
#define CLI_HPP



#include <istream>
#include <iostream>
#include <string>
#include <cstddef>



//Extracts the contents of stream up to, but excluding the newline
//character and stores them in buffer.
//
//Original contents of buffer are lost.
void readInput(std::string &buffer, std::istream &stream = std::cin);


//Returns the number of fields in the line
unsigned int fieldCount(const std::string &input);


unsigned int argumentCount(const std::string &line);
//Returns the number of arguments in the line.
//
//Arguments are any fields after the first.
//
//line must have at least one field.




//Returns true if there are no fields in the line,
//returns false otherwise
bool allFieldsEmpty(const std::string &fields);


//Returns true if the field at index matches the key,
//returns false otherwise
//
//    fieldCount(input) > 0
//    0 <= index < fieldCount(input)
bool fieldIs(const char *key, const size_t index, const char *input);


//Stores the field at index in result.
//
//Original contents of result are lost.
//
//    fieldCount(input) > 0
//    0 <= index < fieldCount(input)
void extractField(
    const std::string &input,
    const size_t index,
    std::string &result);



#endif
