# CLIHelper

## About

*CLIHelper* is a simple lightweight library aimed at easing the pain of building command-line interfaces
and read-eval-print loops by providing user input and argument capturing functions.

## How it works

*CLIHelper* works by simply scanning and lexing strings in-place with the help
of the C++ standard library.

At its core, *CLIHelper* is a lexer and uses the concept of fields (which
can also be thought of as tokens)

A field is simply a substring that contains no spaces.

`"plant"` | *a field*
`"Literary"` | *another field*

When a field contains a space character, it becomes two fields.

`"lucid imagination"` | *a string containing two fields*

Space characters only serve to separate fields; if one or more space characters
appear at either the beginning or end of a field, *CLIHelper* ignores them.

`" snail  "`
`"snail"` | these are the same to *CLIHelper*

Non-alphanumeric characters are treated the same as alphanumeric characters.

`"lucid + snail"` | *three distinct fields*: `"lucid"` `"+"` `"snail"`

Using these concepts, you can parse user input strings like:

    romdump -WHOLE -v --checksum

with no problem at all.

## API at a glance
```c++
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
```
