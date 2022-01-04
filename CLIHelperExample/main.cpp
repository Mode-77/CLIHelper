#include <string>
#include <iostream>

#include "..\cli.hpp"








int main()
{
    std::string userInput;

    while(!fieldIs("quit", 0, userInput.c_str())) {
        std::cout << ">";
        readInput(std::cin, userInput);

        if(allFieldsEmpty(userInput)) {
            continue;
        }

        else if(fieldIs("quit", 0, userInput.c_str())) {
            continue;
        }

        else if(fieldIs("read", 0, userInput.c_str())) {

            if(fieldCount(userInput) == 1) {
                std::cout << "Reading from anywhere\n";
            }

            else if(fieldIs("file", 1, userInput.c_str())) {
                std::cout << "Reading from file\n";
            }

            else if(fieldIs("backup", 1, userInput.c_str())) {
                std::cout << "Reading from backup\n";
            }

            else {
                std::string secondArgument;
                extractField(userInput, 1, secondArgument);
                std::cout << "Unknown option \"" << secondArgument << "\"\n";
            }
        }

        else if(fieldIs("write", 0, userInput.c_str())) {

            if(fieldCount(userInput) == 1) {
                std::cout << "Error: No destination given\n";
            }

            else if(fieldIs("file", 1, userInput.c_str())) {
                std::cout << "Writing to file\n";
            }

            else if(fieldIs("backup", 1, userInput.c_str())) {
                std::cout << "Writing to backup\n";
            }

            else {
                std::string secondArgument;
                extractField(userInput, 1, secondArgument);
                std::cout << "Unknown option \"" << secondArgument << "\"\n";
            }
        }

        else {
            std::string firstArgument;
            extractField(userInput, 0, firstArgument);
            std::cout << "Unknown command \"" << firstArgument << "\"\n";
        }
    }
}
