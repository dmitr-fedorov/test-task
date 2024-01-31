#include "file_reader.h"
#include <fstream>

void FileReader::read(const std::string& fileName,
                      WordsCounter& wordsCounter) const
{
    std::ifstream file(fileName);
    if(!file.is_open())
    {
        throw std::runtime_error("Could not open the input file.");
    }

    std::string word;
    char ch;
    while(file.get(ch))
    {
        if(isFromEnglishAlphabet(ch))
        {
            word += ch;
        }
        else if(!word.empty())
        {
            wordsCounter.add(word);
            word.clear();
        }
    }

    if(!word.empty())
    {
        wordsCounter.add(word);
    }

    file.close();
}

bool FileReader::isFromEnglishAlphabet(char ch) const
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
