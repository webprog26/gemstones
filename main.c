#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100

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
    char* s = "mhydccqrbddfyfoehmkfrbwebcassnqbydblcwrdbnaphlljqolegyxsprmgerjxxckkaxrkmqzdwawpbopdoikhlcof";
    char* s1 = "lttkjeerkhadffxqmfokcwdoicbxpydimobpcnkhzjcgpdigxanczxqw";
    char* s2 = "mbucihazqpoylmfiiturlclabwydqeegdajcmuhrodmfuaeuminwieekuihyuitlnjymjtyxzgokxaubeuovhsdyv";

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

    int controlLength = _strlen(inputedStrings[0]);

    char controlString[controlLength];

    int charMarkers[controlLength];

    //init charMarkers with 0-values
    for(int i = 0; i < controlLength; i++)
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

    _strcopy(inputedStrings[0], controlString);




    //****************************************test is string copied correctly
    /*
    printf("%s\n", controlString);
    */



    return 0;
}
