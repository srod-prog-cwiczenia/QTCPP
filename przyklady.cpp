#include "przyklady.h"

#include <QApplication>
#include <QTextEdit>
#include <QDesktopWidget>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include <exception>

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
    friend bool operator!(const TOsoba &a) {
        return !a.imie.empty() || !a.nazwisko.empty();
    }

    operator bool () const {
        return imie.empty() && nazwisko.empty();
    }
};

Przyklady::Przyklady() {
}

void Przyklady::przeciazanieOperatorow() {

    QTextEdit *te = new QTextEdit();
    // przy okazji prezentacja uzycia auto_ptr - uwaga - to przestarzale!
    auto_ptr<TOsoba> str1(new TOsoba);
    str1->imie = "Adam";
    str1->nazwisko = "Kowalski";

    auto_ptr<TOsoba> str2(new TOsoba);
    str2->imie = "Anna";
    str2->nazwisko = "Nieznana";

    TOsoba *strPtr = new TOsoba("Iwona", "Proba");
    cout << str1->imie << " " << str1->nazwisko << endl;
    te->append((str1->imie + " " + str1->nazwisko).c_str());
    if (*str1 < *str2) {
        te->append("*str1 < *str2");
        cout << "*str1 < *str2" << endl;
    }
    // zastosowanie sortowania poprzez przeciazenie operatora < :
    cout << "-----------------------------------" << endl;
    map<TOsoba, double> mapOsoKwota;
    mapOsoKwota[TOsoba("Anna", "Test")] = 3000.00;
    mapOsoKwota[TOsoba("Dorota", "Nieznana")] = 1000.00;
    mapOsoKwota[TOsoba("Adam", "Kowalski")] = 2000.00;
    for (map<TOsoba, double>::iterator ite = mapOsoKwota.begin(); ite != mapOsoKwota.end(); ite++) {
        std::ostringstream strs;
        strs << ite->second;
        std::string doubleStr = strs.str();
        te->append((ite->first.imie + " " + ite->first.nazwisko +
                   " -> " + doubleStr).c_str());
        cout << ite->first.imie << " " << ite->first.nazwisko <<
            " -> " << ite->second << endl;
    }
    te->show();
}
//-------------------------------------------------------------
void Przyklady::wyjatki() {
  try {
//TODO: ten przykład należy dokończyć
  } catch (exception &E) {
    cout << E.what();
  }
}
//-------------------------------------------------------------
