#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

class WordsCounter
{
public:
    WordsCounter() = default;
    ~WordsCounter() = default;

    void add(const std::string& word);
    friend std::ostream& operator<<(std::ostream& os,
                                    const WordsCounter& wordsCounter);

private:
    std::map<std::string, int> m_counters;

    std::string toLower(const std::string& str) const;
    std::vector<const std::pair<const std::string, int>*> getSortedCounters()
        const;
};
