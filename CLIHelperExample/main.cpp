#include <string>
#include <iostream>

#include "..\cli.hpp"








int main()
{

    while(true)
    {
        std::cout << ">";
        std::string userInput;
        readInput(userInput);

        if(allFieldsEmpty(userInput))
        {
            continue;
        }

        else if(headIs("quit", userInput))
        {
            break;
        }

        else if(headIs("read", userInput))
        {
            if(noArguments(userInput))
            {
                std::cout << "Reading from anywhere\n";
            }
            else
            {
                std::string firstArgument = grabArgument(0, userInput);
                if(firstArgument == "file")
                {
                    std::cout << "Reading from file\n";
                }
                else if(firstArgument == "backup")
                {
                    std::cout << "Reading from backup\n";
                }
                else
                {
                    std::cout << "Unknown option \"" << firstArgument << "\"\n";
                }
            }
        }

        else if(headIs("write", userInput))
        {
            if(noArguments(userInput))
            {
                std::cout << "Error: No destination given\n";
            }
            else
            {
                std::string firstArgument = grabArgument(0, userInput);
                if(firstArgument == "file")
                {
                    std::cout << "Writing to file\n";
                }
                else if(firstArgument == "backup")
                {
                    std::cout << "Writing to backup\n";
                }
                else
                {
                    std::cout << "Unknown option \"" << firstArgument << "\"\n";
                }
            }
        }

        else
        {
            std::string command;
            extractField(userInput, 0, command);
            std::cout << "Unknown command \"" << command << "\"\n";
        }
    }

}
