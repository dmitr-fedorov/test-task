#include "file_writer.h"
#include <fstream>

void FileWriter::write(const std::string& fileName, WordsCounter& wordsCounter) const
{
    std::ofstream file(fileName, std::ofstream::out | std::ofstream::trunc);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open the output file.");
    }

    file << wordsCounter;

    file.close();
}
