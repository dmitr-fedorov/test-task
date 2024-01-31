#pragma once

#include <string>
#include "words_counter.h"

class FileReader
{
public:
    FileReader() = default;
    ~FileReader() = default;

    void read(const std::string& fileName, WordsCounter& wordsCounter) const;

private:
    bool isFromEnglishAlphabet(char ch) const;
};
