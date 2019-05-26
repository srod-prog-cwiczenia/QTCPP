#include "narzedzia.h"
#include <limits>
#include <QMessageBox>
#include <assert.h>
#include <sstream>
//---------------------------------------------------------------------------
CacheString2String::CacheString2String(TString2StringFunkcja aFunkcja, unsigned int aMaxRozmiarCache) {
    maxRozmiarCache = aMaxRozmiarCache;
    trybDzialania = cs2strZlozony;
    calkowitaLiczbaTrafien = calkowitaLiczbaProb = 0;
    fc = aFunkcja;
    cacheMap.clear(); // zbędne zapewne, ale na wszelki wypadek :)
}
//--------------------------------------------------------------------------
void CacheString2String::ustawienieTrybuDzialania(TCacheString2StringTrybDzialaniaEnum aTryb) {
    trybDzialania = aTryb;
}
//--------------------------------------------------------------------------
TCacheString2StringMapaIterator CacheString2String::getMiejsceDoZamiany() {
    if (cacheMap.size() < maxRozmiarCache) return cacheMap.end();
    TCacheString2StringMapaIterator odpIte = cacheMap.begin();
    unsigned int dotychczasowaMinWartosc =  odpIte->second.licznikTrafien;
    for (TCacheString2StringMapaIterator ite = cacheMap.begin();ite != cacheMap.end(); ite++) {
        if (ite->second.licznikTrafien < dotychczasowaMinWartosc) {
            odpIte = ite;
            dotychczasowaMinWartosc = ite->second.licznikTrafien;
        }

    }
    return odpIte;
}
//---------------------------------------------------------------------------
void CacheString2String::getStatystyka(unsigned int *aCalkowitaLiczbaTrafien,
                                       unsigned int *aCalkowitaLiczbaProb) {
  if (aCalkowitaLiczbaTrafien)
    *aCalkowitaLiczbaTrafien = calkowitaLiczbaTrafien;
  if (aCalkowitaLiczbaProb)
      *aCalkowitaLiczbaProb = calkowitaLiczbaProb;
}
//---------------------------------------------------------------------------
string CacheString2String::funkcja(string txt) {
    calkowitaLiczbaProb++;
    if (cacheMap.find(txt) == cacheMap.end()) {
        if (cacheMap.size() == maxRozmiarCache) {
            if (trybDzialania == cs2strProsty) {
                return fc(txt);
            } else {
                TCacheString2StringMapaIterator gdzie = getMiejsceDoZamiany();
                cacheMap.erase(gdzie);
            }
        }
        cacheMap[txt].wartosc = fc(txt);
        cacheMap[txt].licznikTrafien = 0;
        return cacheMap[txt].wartosc;
    } else {
        calkowitaLiczbaTrafien++;
        cacheMap[txt].licznikTrafien++;
        return cacheMap[txt].wartosc;
    }
}
//---------------------------------------------------------------------------
string CacheString2StringTesty::ftest(string aTxt) {
    if (aTxt.length() >= 4) {
        return aTxt.substr(2, 2);
    } else {
        return aTxt + "*";
    }
};
//---------------------------------------------------------------------------
void CacheString2StringTesty::run() {
    CacheString2String *cs = new CacheString2String(ftest);
    //cs->ustawienieTrybuDzialania(cs2strProsty);
    assert(cs->funkcja("Jeden") == "de");
    assert(cs->funkcja("Jeden") == "de");
    assert(cs->funkcja("Siedem") == "ed");
    assert(cs->funkcja("Jeden") == "de");
    assert(cs->funkcja("Siedem") == "ed");
    unsigned int trafienia = 0, proby = 0;
    for (int j = 1; j <= 1000; j++) {
        string lancuch = Narzedzia::int2string(j) + "======";
        string lancuchCache = cs->funkcja(lancuch);
        if (lancuchCache != lancuch.substr(2,2)) {
            Narzedzia::komunikat(lancuch + " " + lancuchCache);
        }
        assert(cs->funkcja(lancuch) == lancuch.substr(2,2));
    }
    for (int j = 1; j <= 1000; j++) {
        string lancuch = Narzedzia::int2string(j) + "======";
        string lancuchCache = cs->funkcja(lancuch);
        if (lancuchCache != lancuch.substr(2,2)) {
            Narzedzia::komunikat(lancuch + " " + lancuchCache);
        }
        assert(cs->funkcja(lancuch) == lancuch.substr(2,2));
    }
    cs->getStatystyka(&trafienia, &proby);
    string kom;
    std::ostringstream strs;
    strs << "Testy udane" << endl;
    strs << "Liczba prob: " << proby << " .Liczba trafien: " << trafienia << endl;
    strs << "Procentowo: " << double(trafienia) / double(proby) * 100.0;
    kom = strs.str();
    delete cs;
    Narzedzia::komunikat(kom);
}
//---------------------------------------------------------------------------
Narzedzia::Narzedzia()
{

}
//---------------------------------------------------------------------------
void Narzedzia::komunikat(string tresc) {
    QMessageBox msgBox;
    msgBox.setText(tresc.c_str());
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}
//---------------------------------------------------------------------------
string Narzedzia::int2string(int aI) {
    string wynik;
    std::ostringstream strs;
    strs << aI;
    wynik = strs.str();
    return wynik;
}
//---------------------------------------------------------------------------
