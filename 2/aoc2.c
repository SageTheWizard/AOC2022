#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_SIZE 1000
#define TOP_N 3

void assert(uint8_t bCond)
{
    if (!bCond)
    {
        printf("Guess that's false..\n");
        *(int *)0 = 0;
    }
}
size_t getAllCalories(int32_t *pnAllCalories)
{
    FILE *pFile = fopen("input.txt", "r");
    char acLine[256] = {0};
    int32_t nCurrentFood = 0;
    int32_t nIndx = 0;
    while (fgets(acLine, sizeof(acLine), pFile))
    {
        if (strcmp(acLine, "\n") == 0)
        {
            *(pnAllCalories + nIndx) = nCurrentFood;
            nCurrentFood = 0;
            nIndx++;
            // I'm not reading that file.. just gonna up the size
            assert(nIndx < MAX_SIZE);
        }
        else
        {
            nCurrentFood += atoi(acLine);
        }
    }

    return nIndx;
}

int greaterThan(const void *x, const void *y)
{
    return (*(int *)x < *(int *)y);
}

int main()
{
    int32_t anCalorieArray[MAX_SIZE] = {-1};
    uint32_t nSize = getAllCalories(anCalorieArray);
    qsort((void *)anCalorieArray, nSize, sizeof(int32_t), greaterThan);

    uint32_t nTotal = 0;
    for (uint8_t i = 0; i < 3; i++)
    {
        printf("#%d -- %d\n", i + 1, anCalorieArray[i]);
        nTotal += anCalorieArray[i];
    }
    printf("Total: %u\n", nTotal);
}