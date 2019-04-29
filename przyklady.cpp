#include "przyklady.h"

#include <QApplication>
#include <QTextEdit>
#include <QDesktopWidget>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QMessageBox>

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include <exception>

// jesli korzystamy z modulu bez widgetow to nalezy dac define BEZ_WIDGETOW
#undef BEZ_WIDGETOW

using namespace std;

struct TOsoba {
    string imie, nazwisko;
    TOsoba() {};
    TOsoba(string aImie, string aNazwisko) : imie(aImie), nazwisko(aNazwisko) {};
    friend bool operator<(const TOsoba &a, const TOsoba &b) {
        if (a.nazwisko < b.nazwisko) return true;
        if (a.nazwisko > b.nazwisko) return false;
        if (a.imie < b.imie) return true;
        if (a.imie > b.imie) return false;
        return false;
    }
    friend bool operator>(const TOsoba &a, const TOsoba &b) {
        return b < a;
    }
    friend bool operator==(const TOsoba &a, const TOsoba &b) {
        return a.imie == b.imie && a.nazwisko == b.nazwisko;
    }
    friend bool operator!(const TOsoba &a) {
        return !(bool)a;
    }
    operator bool () const {
        return !imie.empty() || !nazwisko.empty();
    }
};

Przyklady::Przyklady() {
}

void Przyklady::przeciazanieOperatorow() {

#ifndef BEZ_WIDGETOW
    QTextEdit *te = new QTextEdit();
#endif
    // przy okazji prezentacja uzycia auto_ptr - uwaga - to przestarzale!
    auto_ptr<TOsoba> str1(new TOsoba);
    str1->imie = "Adam";
    str1->nazwisko = "Kowalski";

    auto_ptr<TOsoba> str2(new TOsoba);
    str2->imie = "Anna";
    str2->nazwisko = "Nieznana";

    TOsoba *strPtr = new TOsoba("Iwona", "Proba");
#ifdef BEZ_WIDGETOW
    cout << str1->imie << " " << str1->nazwisko << endl;
#else
    te->append((str1->imie + " " + str1->nazwisko).c_str());
#endif
    if (*str1 < *str2) {
        cout << "*str1 < *str2" << endl;
        te->append("*str1 < *str2");
    }
    // zastosowanie sortowania poprzez przeciazenie operatora < :
    cout << "-----------------------------------" << endl;
    map<TOsoba, double> mapOsoKwota;
    mapOsoKwota[TOsoba("Anna", "Test")] = 3000.00;
    mapOsoKwota[TOsoba("Kamila", "Nieznana")] = 1000.00;
    mapOsoKwota[TOsoba("Adam", "Kowalski")] = 2000.00;
    mapOsoKwota[TOsoba("Dorota", "Koralewska")] = 4000.00;
    for (map<TOsoba, double>::iterator ite = mapOsoKwota.begin(); ite != mapOsoKwota.end(); ite++) {
        std::ostringstream strs;
        strs << ite->first.imie << " " << ite->first.nazwisko <<
            " -> " << ite->second << endl;
        string txt = strs.str();
#ifdef BEZ_WIDGETOW
        cout << txt;
#else
        te->append(txt.c_str());
#endif
    }
    te->show();
}
//-------------------------------------------------------------
void Przyklady::wyjatki() {
    try {
        throw "Wyjatek wlasny";
    } catch (const char* e) {
        ostringstream strs;
        strs << "Nastapil wyjatek: " << e;
        string txt = strs.str();
#ifdef BEZ_WIDGETOW
        cout << txt << endl;
#else
        QMessageBox msgBox;
        msgBox.setText(txt.c_str());
        //msgBox.setInformativeText("");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
#endif
    }
}
//-------------------------------------------------------------
void Przyklady::wskazniki1() {
    //podwojny wskaznik:
    char c[10][10];
    char *wsk = (char *)c;
}
//-------------------------------------------------------------
void Przyklady::wskazniki2() {
// proste ustawianie wskaznika oraz alokowanie i jego zwalnianie
    int *ptr = NULL; //wskaźnik na int
    int licznik = 13;
    //ustawienie wskaźnika na licznik:
    ptr = &licznik;
    ptr = NULL; //znów wracamy do pustego wskazania
                //ale można też pobrać pamięć dla wskaźnika:
    ptr = new int;
    *ptr = 17;
    // a potem ją zwolnić
    delete ptr;
}
//-------------------------------------------------------------
void Przyklady::wskazniki3() {
    /*
      ktoś umieścił w kodzie programu tablicę (liczba dni poszczegolnych miesiecy):
    */
    unsigned int liczbaDni[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //bez wskaźników przesumowanie elementów tej tablicy jest łatwe:
    unsigned int suma = 0;
    for (int i = 0; i < 12; suma += liczbaDni[i++]);
    cout << "Suma dni: " << suma << endl;
    //zadanie: przesumować za pomocą wskaźników:
    suma = 0;
    for (unsigned int *wsk = liczbaDni; wsk <= &liczbaDni[11]; wsk++) {
        suma += *wsk;
    }
    cout << "Suma dni obliczona wskaźnikami: " << suma << endl;
// zadanie: jak zmodyfikowac ten łańcuch, np. zmienić litery na duże:
    char *lancuch = "Dzis jest dwudziesty ósmy dzień kwietnia!";
    //nie ma rady, trzeba skopiować go na inny obszar pamięci:
    //najpierw alokujemy pamięć:
    char *kopiaStr = (char *)malloc(strlen(lancuch) + 1);
    //strcpy_s(kopiaStr, strlen(lancuch) + 1, lancuch);
    char *source = lancuch;
    char *dest = kopiaStr;
    /*while (*source) {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';*/ // poniżej jest bardzo zwarty kod:

    while (*dest++ = *source++);

    cout << "Tu powinien być dłuuuugi łańcuch: " << kopiaStr << endl;
    free(kopiaStr);
}
//-------------------------------------------------------------
void Przyklady::wskazniki() {
  wskazniki1();
  wskazniki2();
  wskazniki3();
}
//-------------------------------------------------------------
/*
  Przyklad uzycia szablonu:
*/
template <typename T>
 class TTrojka
 {
    public:
       TTrojka(T aX, T aY, T aZ ): x(aX), y(aY), z(aZ) {}
       T x, y, z;
 };
//-------------------------------------------------------------
void Przyklady::kopiowanieCharGwiazdka() {
    //stały napis (,,niemutowalny'')
    const char *napis = "Dziś jest poniedziałek";
    //alokacja pamięci na kopię łańcucha
    char *strWsk = (char *)malloc(strlen(napis) + 1);
    //kopiujemy napis:
    //strcpy_s(strWsk, strlen(napis) + 1, napis);
    char *ws = (char *)napis;
    char *wd = strWsk;
    while (*wd++ = *ws++);
    cout << "Tu powinien być napis: " << strWsk << endl;
    //trzeba się ,,przejść'' po strWsk i pozamieniać małe litery na duże
    wd = strWsk;
    //wersja 1:
    /*while (*wd) {
        *wd++ = toupper(*wd);
    }*/

    // wersja 2
//	while (*wd++ = toupper(*wd));

    // wersja 3:
    //while (*wd++ = ('a' <= *wd && *wd <= 'z' ? *wd - 32 : *wd));

    for (char *wsk = strWsk; *wsk; wsk++) {
        if ('a' <= *wsk && *wsk <= 'z')
            *wsk -= 32;
    }
    cout << "Tu powinien być napis dużymi literami: " << strWsk << endl;
    free(strWsk);
}
//-------------------------------------------------------------
