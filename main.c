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
    //test array size
    int t = 3;

    //for production version
    /*
    int t;
    scanf("%d", &t);
    */

    /*
    char userString[MAXLENGTH];
    */

    //test Strings
    /*
    char* s = "mhydccqrbddfyfoehmkfrbwebcassnqbydblcwrdbnaphlljqolegyxsprmgerjxxckkaxrkmqzdwawpbopdoikhlcof";
    char* s1 = "lttkjeerkhadffxqmfokcwdoicbxpydimobpcnkhzjcgpdigxanczxqw";
    char* s2 = "mbucihazqpoylmfiiturlclabwydqeegdajcmuhrodmfuaeuminwieekuihyuitlnjymjtyxzgokxaubeuovhsdyv";
    */

    char* s = "abcdde";
    char* s1 = "baccd";
    char* s2 = "eeabg";

    char inputedStrings[t][MAXLENGTH];

    //test array fill
    _strcopy(s, inputedStrings[0]);
    _strcopy(s1, inputedStrings[1]);
    _strcopy(s2, inputedStrings[2]);


    //****************************************test is array filled correctly
    /*
    for(int i = 0; i < t; i++)
    {
        printf("%s\n", inputedStrings[i]);
    }
    */


    //for production version
    /*
    for(int i = 0; i < t; i++)
    {
        scanf("%s", userString);
        _strcopy(userString, inputedStrings[i]);
    }
    */


    int charMarkers[ALPHABET_LENGTH + 1];

    //init charMarkers with 0-values
    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        charMarkers[i] = 0;
    }

    //****************************************test is charMarkers filled correctly
    /*
    for(int i = 0; i < controlLength; i++)
    {
        printf("%i\n", charMarkers[i]);
    }
    */

    char controlString[_strlen(inputedStrings[0])];
    _strcopy(inputedStrings[0], controlString);


    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < _strlen(inputedStrings[0]); j++)
        {
            if(indexOf(inputedStrings[i], controlString[j]) != -1)
            {
                charMarkers[controlString[j] - SMALL_A_ACII_INDEX]++;
            }
        }
    }

    /*
    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        printf("%i - %c - %i\n", i + 1, i + SMALL_A_ACII_INDEX, charMarkers[i]);
    }
    */

    int totalCounter = 0;

    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        if(charMarkers[i] == t)
        {
            totalCounter++;
        }
    }

    //****************************************test is string copied correctly
    /*
    printf("%s\n", controlString);
    */

    /*
    printf("Total counter is %i\n", totalCounter);
    */

    printf("%i", totalCounter);
    return 0;
}
