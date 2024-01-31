#pragma once

#include "words_counter.h"
#include <string>

class FileWriter
{
public:
    FileWriter() = default;
    ~FileWriter() = default;

    void write(const std::string& fileName, WordsCounter& wordsCounter) const;
};
