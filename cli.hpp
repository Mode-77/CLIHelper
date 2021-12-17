/*
    File:   cli.hpp
    Author: Jared Thomas
    Date:   Thursday, December 2, 2021
*/


#ifndef CLI_HPP
#define CLI_HPP


#include <istream>
#include <string>
#include <vector>

using std::string;
using std::vector;

void readInput(std::istream &inputStream, std::string &inputString);

void stripLeadingSpaces(string &input);

void grabUntilSpace(string &input);

void grabFromSpace(string &input);

void chop(const string &piece, string &whole);

int fieldCount(const string &input);

void extractField(
    const string &input,
    const size_t index,
    string &result);

int fieldIs(const char *key, const size_t fieldNumber, const char *fields);

bool allFieldsEmpty(const string &fields);

// bool findMatch(const char *key, const char *list[]);

int findMatch(const char *key, const char *list[]);



#endif
