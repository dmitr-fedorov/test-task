#include "words_counter.h"
#include <algorithm>
#include <cctype>

void WordsCounter::add(const std::string& word)
{
    auto wordInLowerCase = toLower(word);

    m_counters[wordInLowerCase]++;
}

std::string WordsCounter::toLower(const std::string& str) const
{
    std::string result;
    for(auto ch : str)
    {
        result += std::tolower(ch);
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const WordsCounter& wordsCounter)
{
    auto sortedCounters = wordsCounter.getSortedCounters();

    for(const auto& counter : sortedCounters)
    {
        os << counter->first << " - " << counter->second << '\n';
    }

    return os;
}

std::vector<const std::pair<const std::string, int>*>
    WordsCounter::getSortedCounters() const
{
    std::vector<const std::pair<const std::string, int>*> result;
    for(auto& counter : m_counters)
    {
        result.push_back(&counter);
    }

    std::sort(result.begin(), result.end(),
              [](const std::pair<const std::string, int>* a,
                 const std::pair<const std::string, int>* b)
              {
                  if(a->second == b->second)
                  {
                      return a->first < b->first;
                  }
                  return a->second > b->second;
              });

    return result;
}
