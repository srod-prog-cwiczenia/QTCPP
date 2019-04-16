#include "bazydanych.h"
#include <iostream>
#include <sqlite3.h>
using namespace std;

bazyDanych::bazyDanych()
{

}
//-------------------------------------------------------
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i=0; i<argc; i++)
    {
        cout<<azColName[i]<<" = " << (argv[i] ? argv[i] : "NULL")<<"\n";
    }
    cout<<"\n";
    return 0;
}
//-------------------------------------------------------
void bazyDanych::przyklad1() {
    const int STATEMENTS = 8;
    sqlite3 *db;
    char *zErrMsg = 0;
    const char *pSQL[STATEMENTS];
    int rc;

    rc = sqlite3_open("listaOsob.db", &db);

    if( rc )
    {
        cout<<"Nie moge otworzyc bazy: " << sqlite3_errmsg(db) << endl;
    }
    else
    {
        cout<<"Poprawnie otworzylem baze" << endl << endl;
    }

    pSQL[0] = "CREATE TABLE OSOBY (IMIE VARCHAR(30), NAZWISKO VARCHAR(30), WIEK NUMERIC(3,0), OPIS VARCHAR(30))";

    pSQL[1] = "INSERT INTO OSOBY (IMIE, NAZWISKO, WIEK, OPIS) VALUES ('Adam', 'Kowalski', 30, 'pracownik')";

    pSQL[2] = "INSERT INTO OSOBY (IMIE, NAZWISKO, WIEK, OPIS) VALUES ('Anna', 'Nieznana', 15, 'uczen')";

    pSQL[3] = "INSERT INTO OSOBY (IMIE, NAZWISKO, WIEK, OPIS) VALUES ('Karolina', 'Kowalska', 20, 'student')";

    pSQL[4] = "INSERT INTO OSOBY (IMIE, NAZWISKO, WIEK, OPIS) VALUES ('Dominik', 'Nieznany', 40, 'pracownik')";

    pSQL[5] = "SELECT * FROM OSOBY";

    pSQL[6] = "DELETE FROM OSOBY";

    pSQL[7] = "DROP TABLE OSOBY";

    for(int i = 0; i < STATEMENTS; i++)
    {
        rc = sqlite3_exec(db, pSQL[i], callback, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            cout<<"SQL error: "<<sqlite3_errmsg(db)<<"\n";
            sqlite3_free(zErrMsg);
            break;
        }
    }

    sqlite3_close(db);
}
//----------------------------------------------------------------------

