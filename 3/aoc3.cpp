#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#define READ_BUFFER_SIZE 256

uint32_t itemToPriority(char cItem)
{
    return (cItem >= 'a' ? (cItem - 'a') + 1 : (cItem - 'A') + 27);
}
uint32_t findCommonPriority()
{
    FILE *pFile = fopen("input.txt", "r");
    char acReadBuffer[READ_BUFFER_SIZE] = {0};
    std::string sRucksack;
    std::string sRucksackPocketOne;
    std::string sRucksackPocketTwo;
    std::vector<char> oFoundAlready = std::vector<char>();
    uint32_t nCount = 0;

    while (fgets(acReadBuffer, sizeof(acReadBuffer), pFile))
    {
        sRucksack = acReadBuffer;
        sRucksackPocketOne = sRucksack.substr(0, sRucksack.length() / 2);
        sRucksackPocketTwo = sRucksack.substr(sRucksack.length() / 2);
        sRucksackPocketTwo.erase(std::remove(sRucksackPocketTwo.begin(), sRucksackPocketTwo.end(), '\n'), sRucksackPocketTwo.end());

        for (size_t i = 0; i < sRucksackPocketOne.length(); i++)
        {
            if (sRucksackPocketTwo.find(sRucksackPocketOne.c_str()[i]) != std::string::npos &&
                std::find(oFoundAlready.begin(), oFoundAlready.end(), sRucksackPocketOne.c_str()[i]) == oFoundAlready.end())
            {
                oFoundAlready.push_back(sRucksackPocketOne.c_str()[i]);
                nCount += itemToPriority(sRucksackPocketOne.c_str()[i]);
            }
        }
        oFoundAlready.clear();
    }
    fclose(pFile);
    return nCount;
}

int main()
{
    uint32_t nPriority = findCommonPriority();
    printf("%d\n", nPriority);
}