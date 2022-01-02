/*
    File:   cli.hpp
    Author: Jared Thomas
    Date:   Thursday, December 2, 2021
*/


#ifndef CLI_HPP
#define CLI_HPP


#include <istream>
#include <string>

using std::string;


void readInput(std::istream &inputStream, std::string &inputString);

void stripLeadingSpaces(std::string &input);

void grabUntilSpace(std::string &input);

void grabFromSpace(std::string &input);

void chop(const std::string &piece, std::string &whole);

int fieldCount(const std::string &input);

void extractField(
    const std::string &input,
    const size_t index,
    std::string &result);

int fieldIs(const char *key, const size_t fieldNumber, const char *fields);

bool allFieldsEmpty(const std::string &fields);

// bool findMatch(const char *key, const char *list[]);

int findMatch(const char *key, const char *list[]);



#endif
