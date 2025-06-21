#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <cstring>
#include <stdexcept>


void FindLongestWords(const char* inputStr, const char* seps, char* result)
{
    int32_t maxLen{ 0 };
    result[0] = '\0';
    int32_t currentWordStart{ -1 };
    int32_t currentWordLen{ 0 };
    int32_t i { 0 };
    while (true) 
    {
        char c = inputStr[i];
        bool isDelim = false;
        if (c == '\0' || (seps[0] != '\0' && std::strchr(seps, c) != nullptr)) 
        {
            isDelim = true;
        }
        if (!isDelim) 
        {
            if (currentWordLen == 0) 
            {
                currentWordStart = i;
            }
            ++currentWordLen;
        }
        if (isDelim && currentWordLen > 0) 
        {
            if (currentWordLen > maxLen) 
            {
                maxLen = currentWordLen;
                result[0] = '\0';
                std::strncat(result, &inputStr[currentWordStart], currentWordLen);
            }
            else if (currentWordLen == maxLen && maxLen != 0) 
            {
                std::strcat(result, "; ");
                std::strncat(result, &inputStr[currentWordStart], currentWordLen);
            }
            currentWordLen = 0;
        }
        if (c == '\0') 
        {
            break;
        }
        ++i;
    }
    if (maxLen == 0) 
    {
        throw std::runtime_error("Cannot solve the problem: no words found.");
    }
}