#include "log_file.h"
#include <chrono>
#include <iomanip>

LogFile::~LogFile()
{
    m_file.close();
}

void LogFile::open(const std::string& fileName)
{
    m_file.open(fileName, std::ofstream::out | std::ofstream::app);
}

void LogFile::write(const std::string& str)
{
    if(!m_file.is_open())
    {
        return;
    }

    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm* tm = std::localtime(&time);

    m_file << std::put_time(tm, "%d-%m-%Y %H:%M:%S") << " | " << str << "\n";
}
