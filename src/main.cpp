#include <fstream>
#include "file_reader.h"
#include "words_counter.h"

#define DEFAULT_INPUT_FILE_NAME "WordsList.txt"

int main()
{
    FileReader fileReader;
    WordsCounter wordsCounter;

    try
    {
        fileReader.read(DEFAULT_INPUT_FILE_NAME, wordsCounter);
    }
    catch(std::exception& e)
    {
        return -1;
    }

    return 0;
}
