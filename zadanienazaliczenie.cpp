#include "zadanienazaliczenie.h"

ZadanieNaZaliczenie::ZadanieNaZaliczenie()
{

}
/*
Napisać aplikację która będzie ,,zarządzać'' kolekcją
prostych danych o osobach (wystarczy imię i nazwisko)
czyli na przykład tak:

struct TOsoba {
  string imie,nazwisko;
};
i dalej na przykład tak: std::vector<TOsoba> kolekcja;

Powinny być dostępne trzy opcje:
1. Przeglądanie: po jej uruchomieniu powinna
być wyświetlona lista osób z kolekcji (odpowiednio, z bazy danych)
proponowana postać listy to:
<lp><imię><nazwisko>
itd...
2. Dopisanie: po wywołaniu tej opcji program powinien zapytać
o imię osoby, jej nazwisko a potem umożliwić dopisanie
następnej, i tak w pętli. Wyjście z tej pętli powinno się
dać osiągnąć ot na przykład poprzez podanie pustego imienia i nazwiska
(tutaj zostawiam dowolność - i liczę na Państwa pomysłowość).

3. Usuwanie: na początek wyświetlamy listę jak w punkcie 1.
a potem pytamy o liczbę porządkową osoby do usunięcia.

W punktach 1. i 3. można ewentualne (to będzie dodatkowo punktowane!)
zadbać o ,,scrollowanie'' w przypadku kiedy lista nie będzie
w stanie zmieścić się w całości na ekranie.

Na ocenę bdb należy zamiast kolekcji użyć bazy danych
(dowolność wyboru - można sqlite3 albo połączyć się
przez ODBC z zainstalowaną, do wyboru, aby 
tylko program funkcjonował w tym przypadku poprzez SQL).
*/
