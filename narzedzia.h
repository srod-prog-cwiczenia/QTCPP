#ifndef NARZEDZIA_H
#define NARZEDZIA_H

#include <string>
#include <map>
using namespace std;
struct CacheString2StringStruktura {
    string wartosc;
    unsigned int licznikTrafien;
};
typedef string (*TString2StringFunkcja)(string);
typedef std::map<string,CacheString2StringStruktura> TCacheString2StringMapa;
typedef TCacheString2StringMapa::iterator TCacheString2StringMapaIterator;
enum TCacheString2StringTrybDzialaniaEnum {
    cs2strProsty, cs2strZlozony
};
class CacheString2String {
private:
    TCacheString2StringTrybDzialaniaEnum trybDzialania;
    unsigned int maxRozmiarCache;
    unsigned int calkowitaLiczbaTrafien, calkowitaLiczbaProb;
    TString2StringFunkcja fc;
    TCacheString2StringMapa cacheMap;
    TCacheString2StringMapaIterator getMiejsceDoZamiany();
public:
    CacheString2String(TString2StringFunkcja aFunkcja, unsigned int aMaxRozmiarCache = 100);
    string funkcja(string txt);
    void getStatystyka(unsigned int *aCalkowitaLiczbaTrafien, unsigned int *aCalkowitaLiczbaProb);
    void ustawienieTrybuDzialania(TCacheString2StringTrybDzialaniaEnum aTryb);
};

class CacheString2StringTesty {
public:
    static string ftest(string aTxt);
    static void run();
};

class Narzedzia
{
public:
    Narzedzia();
    static void komunikat(string tresc);
    static string int2string(int aI);
};

#endif // NARZEDZIA_H
