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



//Returns the contents of stream up to, but excluding the newline character.
std::string readInput(std::istream &stream = std::cin);


//Returns true if there are no fields in the line or false
//if the line has at least one field.
bool allFieldsEmpty(const std::string &line);


//Returns the number of fields in the line.
unsigned int fieldCount(const std::string &line);


//Returns true if the field at index matches the key,
//returns false otherwise
//
//    fieldCount(line) > 0
//    0 <= index < fieldCount(line)
bool fieldIs(const std::string &key, size_t index, const std::string &line);


//Returns the field at index in the line.
//
//    fieldCount(line) > 0
//    0 <= index < fieldCount(line)
std::string grabField(size_t index, const std::string &line);


//Returns true if the head field matches the key or false
//if it does not.
//
//The head field is the first field in the line.
//
//line must have at least one field.
bool headIs(const std::string &key, const std::string &line);


//Returns true if line has no arguments or false if it has
//at least one argument.
//
//line must have at least the head field.
bool noArguments(const std::string &line);


//Returns the number of arguments in the line.
//
//Arguments are any fields after the first.
//
//line must have at least one field.
unsigned int argumentCount(const std::string &line);


//Returns true if the Nth argument matches key or false
//if it does not.
//
//line must have at least one argument.
//N must be in the range [0, argumentCount(line) - 1].
bool argumentIs(const std::string &key, size_t N, const std::string &line);


//Returns the Nth argument in the line.
//
//line must have at least one argument.
//N must be in the range [0, argumentCount(line) - 1].
std::string grabArgument(size_t N, const std::string &line);


#endif
