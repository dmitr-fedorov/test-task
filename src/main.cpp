#include <fstream>
#include "file_reader.h"
#include "file_writer.h"
#include "words_counter.h"

#define DEFAULT_INPUT_FILE_NAME "WordsList.txt"
#define DEFAULT_OUTPUT_FILE_NAME "ResultPairs.txt"

int main()
{
    FileReader fileReader;
    FileWriter fileWriter;
    WordsCounter wordsCounter;

    try
    {
        fileReader.read(DEFAULT_INPUT_FILE_NAME, wordsCounter);
        fileWriter.write(DEFAULT_OUTPUT_FILE_NAME, wordsCounter);
    }
    catch(std::exception& e)
    {
        return -1;
    }

    return 0;
}
