#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100
#define ALPHABET_LENGTH 26

#define SMALL_A_ACII_INDEX 97

int indexOf(char* s, char c)
{
    char* sp = s;

    int flag = -1;

    while(*s)
    {
        if(*s == c)
        {
            flag = s - sp;
            return flag;
        }
        s++;
    }
    return flag;
}

void _strcopy(char* from, char* to)
{
    while(*from)
    {
        *to = *from;
        from++;
        to++;
    }
    *to = '\0';
}

int _strlen(char* s)
{
    int counter = 0;

    while(*s)
    {
        counter++;
        s++;
    }

    return counter;
}

int main()
{
    int t;
    scanf("%d", &t);

    char userString[MAXLENGTH];

    char inputedStrings[t];

    for(int i = 0; i < t; i++)
    {
        scanf("%s", userString);
        _strcopy(userString, inputedStrings[i]);
    }



    int charMarkers[ALPHABET_LENGTH + 1];

    //init charMarkers with values
    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        charMarkers[i] = 0;
    }


    char controlString[ALPHABET_LENGTH];

    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        controlString[i] = i + SMALL_A_ACII_INDEX;
    }


    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < ALPHABET_LENGTH; j++)
        {
            if(indexOf(inputedStrings[i], controlString[j]) != -1)
            {
                charMarkers[controlString[j] - SMALL_A_ACII_INDEX]++;
            }
        }
    }

    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        printf("%i - %c - %i\n", i + 1, i + SMALL_A_ACII_INDEX, charMarkers[i]);
    }


    int totalCounter = 0;

    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        if(charMarkers[i] == t)
        {
            totalCounter++;
        }
    }


    printf("%i", totalCounter);
    return 0;
}
