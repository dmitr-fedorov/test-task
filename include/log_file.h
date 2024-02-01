#pragma once

#include <fstream>
#include <string>

class LogFile
{
public:
    LogFile() = default;
    ~LogFile();

    void open(const std::string& fileName);
    void write(const std::string& str);

private:
    std::ofstream m_file;
};
