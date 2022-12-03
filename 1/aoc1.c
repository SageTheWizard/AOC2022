#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define READ_BUFFER_SZ 256

int32_t getMaxCalories()
{
    FILE *pFile = fopen("input.txt", "r");

    char acLine[READ_BUFFER_SZ] = {0};
    int32_t nCurrentFood = 0;
    int32_t nAnswer = 0;

    while (fgets(acLine, sizeof(acLine), pFile))
    {
        if (strcmp(acLine, "\n") == 0)
        {
            if (nCurrentFood > nAnswer)
            {
                nAnswer = nCurrentFood;
            }
            nCurrentFood = 0;
        }
        else
        {
            nCurrentFood += atoi(acLine);
        }
    }
    fclose(pFile);
    return nAnswer;
}

int main()
{
    uint32_t nAnswer = getMaxCalories();
    printf("The Answer is %d\n", nAnswer);
}