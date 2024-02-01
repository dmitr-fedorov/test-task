#include <fstream>
#include "file_reader.h"
#include "file_writer.h"
#include "log_file.h"
#include "words_counter.h"

#define DEFAULT_INPUT_FILE_NAME "WordsList.txt"
#define DEFAULT_OUTPUT_FILE_NAME "ResultPairs.txt"
#define DEFAULT_LOG_FILE_NAME "log.txt"

int main()
{
    FileReader fileReader;
    FileWriter fileWriter;
    WordsCounter wordsCounter;
    LogFile logFile;

    try
    {
        logFile.open(DEFAULT_LOG_FILE_NAME);

        fileReader.read(DEFAULT_INPUT_FILE_NAME, wordsCounter);
        fileWriter.write(DEFAULT_OUTPUT_FILE_NAME, wordsCounter);

        logFile.write("Words counted successfully.\n");
    }
    catch(std::exception& e)
    {
        logFile.write(std::string(e.what()) + "\n");
        return -1;
    }

    return 0;
}
