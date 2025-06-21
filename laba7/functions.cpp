#include "functions.h"


bool isDelimiter(char ch) 
{
    if (ch == ' ' || ch == '\t' || ch == '\n')
    {
        return true;
    }
    const char* punctuation{ ".,!?;:-()[]{}\"'" };
    for (const char* p{ punctuation }; *p != '\0'; ++p) 
    {
        if (ch == *p)
        {
            return true;
        }
    }
    return false;
}

bool isStrictlyAscending(const std::string& word) 
{
    if (word.empty())
    {
        return false;
    }
    for (size_t i{ 0 }; i < word.size() - 1; ++i) 
    {
        if (word[i] >= word[i + 1])
        {
            return false;
        }
    }
    return true;
}

std::string processInput(const std::string& input) 
{
    std::string currentWord{};
    std::string result{};
    std::size_t maxLen{ 0 };
    for (size_t i{ 0 }; i <= input.size(); ++i) 
    {
        if (i < input.size() && !isDelimiter(input[i])) 
        {
            currentWord.push_back(input[i]);
        }
        else 
        {
            if (!currentWord.empty()) 
            {
                if (isStrictlyAscending(currentWord)) 
                {
                    if (currentWord.size() > maxLen) 
                    {
                        maxLen = currentWord.size();
                        result = currentWord;
                    }
                    else if (currentWord.size() == maxLen) 
                    {
                        if (!result.empty()) 
                        {
                            result += ' ';
                        }
                        result += currentWord;
                    }
                }
                currentWord.clear();
            }
        }
    }
    return result;
}