#include "CppUTest/TestHarness.h"

#include <fstream>

#define TEST_TEXT_FILES_HOME    "test_txt/"



TEST_GROUP(InputFileStream)
{

};



TEST(InputFileStream, inputFileStream_FailBitIsSetOnInvalidFile)
{
    std::ifstream nonexistentFile("non-existent.txt", std::ifstream::in);

    CHECK_FALSE(nonexistentFile.is_open());
    // failbit is set, but badbit is NOT set
    CHECK(nonexistentFile.fail() && (!nonexistentFile.bad()));
}



TEST(InputFileStream, inputFileStream_GoodBitIsSetOnValidFile)
{
    std::ifstream existentFile(TEST_TEXT_FILES_HOME"test_input.txt", std::ifstream::in);

    CHECK(existentFile.is_open());
    CHECK(existentFile.good());

    existentFile.close();
    CHECK_FALSE(existentFile.is_open());
}



TEST(InputFileStream, inputFileStream_OpenFileAutomaticallyClosesWhenDestroyed)
{
    std::ifstream existentFile(TEST_TEXT_FILES_HOME"test_input.txt", std::ifstream::in);
}
