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
    int t = 100;

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

    char inputedStrings[][MAXLENGTH] = {
    "mhydccqrbddfyfoehmkfrbwebcassnqbydblcwrdbnaphlljqolegyxsprmgerjxxckkaxrkmqzdwawpbopdoikhlcof",
    "lttkjeerkhadffxqmfokcwdoicbxpydimobpcnkhzjcgpdigxanczxqw",
    "mgseqfwduoddcbaautnebrlcbup",
    "mbucihazqpoylmfiiturlclabwydqeegdajcmuhrodmfuaeuminwieekuihyuitlnjymjtyxzgokxaubeuovhsdyv",
    "jadbjfecdxujcv",
    "nbabvhbcycofyxfjyjlesivgktipqgppxrpehedsqyexgnizvfzuotsehtzecmysrdkkdlzexfbfesi",
    "tfnvcmdhucpkmivexfugcldoizvdzvwsarwrdzponwuqpfscubxgyyebbfcruykjnylwafwesgnepmpzslnwfoivqltfodujrdxq",
    "rcrbfgfifnkyfbecprqdseiraxn",
    "jsevbvdpbikuxwpfkecvbpdqnankobafidnqtemjogerwejxcymqklademjzrzsfmfaocsxtnxplhog",
    "fdsvnuaecebb",
    "xjnlbbivqdjbnfpxlgzcdasqkvmgkecccztvzegivhgphxofvcvslotpdae",
    "znkdufrahjhczdfgfebxybwerjxfjcihvxnyynqppirlhxccaopcahmpxjbrhwcludujvdefsircxzdfkulaq",
    "ngccvzyrzzvafzrqcvenitmcvdgtczaakatqcubdqnpyjfyzdjacamircjnmxadusrwlbufsldsxwqcpebk",
    "xlxjqndenptvbgdotomcayasfzwb",
    "himsttquvmfqwfngixssaynrcbeojlbcvddsmlpkppogbugwcjjsubtjyjstwhbwdodnaevauetoaswsonfewyfqstdqdxygbh",
    "sniwtrllzearkesrdnkflewhpffqsuvljcflqfskmipqxijasbodgzyikgtvsyzbhcqtxqfocjkxiexmdqqsscybegdzc",
    "ecimqpxcxysbqnimtkqzoaehxfxaivvxnlmnqfpborbqdjviasborjhvymjoefgm",
    "grrrmvepgfdlrueukgfcbpcbtcamauuklqseltwotpdapx",
    "prxlpvqagzevfifbrcnurhftqabwptwwwjdjeptbwyfudcqdoycefmopaslqexndae",
    "ugbjakqvgcxtowsaxnjncekucilbmaimecltfafunvzbujbdigjpacfcmmutq",
    "zlhdtpyorgfjruedqyjjbgyhlxdudeodtqaveeezkssyaxzeynylomaadyqcyngvsjxldffiyqdl",
    "itqderqcfonmaueb",
    "tundbyaetuzojpdatiggzyywhfjqsiqukydyxetapkxrjwsoqviurqnhnfysowgcgaomndkieqlcbblzkoxbdottd",
    "vepeubiwfdcrfkdauh",
    "qhlsmbqddaafenetxymfwkwexqeimefammoykgegqpvhwjsotplpnwxjnzmrncun",
    "dawecbadflt",
    "fanpdcdrbltudukpyedgfxmrx",
    "qdxkbaealcflbccelphkxwwtsqjmmzasikqmyshvqczhbodkepifqwxtbidpedivceichjmanigv",
    "faxdajrlfnngyebzfchatee",
    "etydnmybnhmuttdqrxdyoufhtpnmilsziuqiunjcmgnwvanhqwvtasdkatgbjjixblgq",
    "tbcenefzdqfzbyuvdicvgcvdumvzdtdvzxeekdetrxvgacrkfobuhg",
    "zkyvrbmcbdfoluciveqwfdaspcokl",
    "cmytbkfjytsupocateyhesgfporwcxikrlniuuwmmpinpbhulheonfdiflirabvpcxegcqqmwqbgfcddfdzswfodrkauiweeafvo",
    "qgyzasungavrawdfelopzteekptizcmvuhjglmejdkwxuahmuuyysvcveyopkofqpanadlpzdbjyoklnenrhaacbvoj",
    "brolcakikbdwfkvxe",
    "wvjwcwpuvzctdkkmsbyhisxbapfhxtjbrakbnsbphzivqrmaduzzbreblcwoccdcspgweuzhpypnkextbvazfyyyrazedfbs",
    "cpgdbfmzeekaj",
    "iebddihfwcbcetbzajwtkdtyhacvnoojapcnwnckajtxtqqjjjcfsrk",
    "efdcocyyanb",
    "fkxvbituhafvbcwfqqityavdihee",
    "fedbetmaajfcqn",
    "ztvtfcgmdqyudszqbdurioahozohyfksnglaemoe",
    "dbphhmjgovjofqurygwqxrpnpkvszzwzieninzzffidfisrqbpshsdfcduttqrhrxaebioacfhjityaochfbsqcmfextop",
    "nfcaivhjsfvrmlbretjmxxcicfvazabhlhfjodlmomhodfnudxhjspgxadixcxrmeadthmvbonkwcltx",
    "bliogsnyiqckoesmobhjfjdrrdrdanpgxhbgbnaackokymfbxvhsfycencswxzcmthfvfdyewmse",
    "gjrzhhqgyhqibhfvapbsfzarrcdnauaiaigpoapjfzjiihrcqwjoyleettyoyzdxwipxvzxteaiossoidgxwefng",
    "dznrpbuycjtkecgcnlelzqbedajzeqxynoapsklpjfoiaccdfbae",
    "bjsrahfxljybyflkyxzwqdffakdycrepb",
    "hfuixlwpadeqxgcgisbcffdzablkaaszkmtehverzsvgycxvztoodby",
    "whrqaxnfoiliqkdduggswhgnyllwgvbtbcwcebuavkltooafprywbdxwivuoleayafjxevqcrhxhopzzbtaxfdfo",
    "ynkcaqkedcoaurgetbpsdxxgbmahcdocbnsuftfnauyuoaabdedfgedoeplpcaknpbgbhewp",
    "bguurjipiceundqdeefriwwchwscymuzzfqmkeptamj",
    "dnznblaeracmf",
    "jkwipragrynjfctmmyljxjvrampdxrulimnctdmqpblbdbuxotczepknecvgeluf",
    "ltkwmiuxxiqidrvcfforqnestzmwvabsfwwqtfbde",
    "bvtcgdaeef",
    "fxznapankhvfxrlkodstiubethvlvvidlbdsoxzsatoujqecipxpteeyeiy",
    "lsbfajqgbbwjxotfdvvrfanmiknevkhdqzauleqioqmcjtnjvpbvaxrmtkbdvswiglpccdsgnttafbsglradpaebegie",
    "tkefjgpekxcddbhuoriaxkrusulojdcclfsmcjtnffyaudvviyeediymvhuvczhrmnszazxuilykrgaafbgdbpkulsdec",
    "teadtbudfcjpkbecdasgoieeetgaeodbfbctkusijoffvcxd",
    "emsybxqpgwmirtipgvctytpnwcydxocbbmzohchewevscuozmfmxhxjklswpkrkzieanpanhkspyzzqievwch",
    "sydjefbwac",
    "wkxjvavbqmckztqygcagictftsdtegyrixoakxvnzciwqelsxpfpngadkdaogggidllonsilzjaijpgjpjeob",
    "orguunfyozcoxlzhrbyeliwnwajanotjaqzusjjjchfunqffdimqjxbhzpwlamuoaokajk",
    "uxxeukfmrgdanipanqsnqvkbficdadrclbckpbqhalfloekx",
    "bkwqjfywwejfkdkaomfxwbheyiwqsrjakwlathpxlcibshpgtkpekmgowjzlwegagbwqisgsqwuatkqabcyotwdv",
    "vqbcibifaheknsckccnttuzayeligdks",
    "pqrcbcaofvcftcmdottdfdoazepgvaiuvvboldzkmsu",
    "eiygneoyhmvgjpcvbcohvbsocaksbolzbuvmdvocmyccmdqjcchdfdabxmrxyhdmsqpsodyucvgrnacpgrtduwtyuigsmae",
    "ofmpbdmyhfzmgedccrygswcwlmjfwgmbvyfayxxtc",
    "oewsnywgdfxvwmogrsiohdronieyvdladdvkeyfaudvcxcicnmlaacrdgoropfwbincltutqemnfsyy",
    "ivhcbpcubhewfobtpchrztzxpiehwqavjigqdlssgtfxnbuebkpomagtqjeeyjughjorrehatg",
    "zrjkaazaxiphifghbquwwzphgodamkcysaezuzdvqcpzwtkfclhduofamsveutxcbtafaio",
    "cltgbyfyojchdpqokgzaupvuykqgeumojkdehmikavkmiowxjcsazvlwvw",
    "ichlkyzdskptljfzsbfydemnkftjjyahjaqdbcjjgwdprobretrbdribdapfk",
    "fezclofbtwansdc",
    "prackrfzxyxhocmzssaebgtriipnascagcvjwwaqwmabecskjvbfpdygpmbgu",
    "aecefbd",
    "pkfopoykbrewitdkmiftenfacjojjag",
    "bqppsapszxyhsptfckastzwzrdihwricepzsbbfrirujkqgjbiuafrbvpmwfau",
    "thkxanyzdazfqoconysebxnf",
    "fvgljqbsxopfeaeccqkvfpbbyqzevljjdrfveshcsbfgttsbchdszmhbztgtnxxhkxcaadjkwxlobsbtjuuyeuqcs",
    "lkuravcjvwrkjhzjhxhnrmfbsfdebskgbybxoataopobavjahoolvtqymnnfnjl",
    "frppvxthytwcwkmumstqqztykwmdjlspjavihdfebqvbgqubazszqwelblrrhxdbcwldhscavxbg",
    "wldpczzyngffbpsbmdicpuqaplxfgptjtspmqvwywynmxdvgslaiiabcrjnigjnzreohkatblpkhddkuwzfbhjxxqhoajh",
    "dvgshpkfncezmlhlnnhcyyudtumredygxywvrlodejzxjpbeuzzqgakfjlfdtkshtrqpyrgzphkpvsehqbba",
    "jgbscqkwykjefwxmqcdqfdzmdqweklcefzjwfawqhfmayhaunbeksryynxeiuym",
    "ncfkvioekdnsabctxi",
    "bcoezrxhcezfebdgrvmkawebqrfwmbhtryoeoplvzzscnbvlpi",
    "uvtmlxytzcofsfejjwnaqvoxymoaegaemlbunjdidpzknndyweqpbeivzmzdpbvy",
    "oijhpvpoaerahmjccnhacdaleewwfpsjvyuxpeomjccxeednbhkopmxxbhvuedkwpfxyjqnxwynqkwkhyyy",
    "jyvdtokeyyqgbkxzdjhhdoggalewmqburzeaotqgoxpswkawcmvzufltnsslyyacbldbzzwsgbefufu",
    "enzlvplxqotjafixlgorvcdqifnotkeyadutmpkasxqyfvelnyqdwkagdeqlhrab",
    "ymnyaftenfppwmizdzfbjcywljagzmvcuuffrdppzracuvgdtedhosdvweivbhtob",
    "errdfjooqcguagradqkgxtkqbpjxxyqnhvwszkmuxjncjejg",
    "fuebpkcad",
    "opdbnrjqcgigfbmuzdcdpdraoextgrc",
    "foddwyjlkfsbscauzaetu",
    "alttoevdudknudqjcqyimpvcrozhftbbemualsrwgcojbpehhfpaorzatbadwrszapilpzt",
    "noaygksfosrpglmglkzbklxjdnqtjhatpsqqcgoiohrwqdfzpaaerhchlcnkohtrnheyxcpehrz"
    };

    //test array fill
    //_strcopy(s, inputedStrings[0]);
    //_strcopy(s1, inputedStrings[1]);
    //_strcopy(s2, inputedStrings[2]);


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

    char controlString[ALPHABET_LENGTH];

    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        controlString[i] = i + 97;
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
