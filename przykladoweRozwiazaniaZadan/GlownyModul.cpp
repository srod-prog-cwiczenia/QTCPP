// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TMenu.h"

//--------------------------------
void zadanieNr1Wskazniki() {
	int *wskI = new int;
	*wskI = 7;
	cout << "wskI bez gwiazdki: " << wskI << endl;
	cout << "*wskI: " << *wskI << endl;
	delete wskI;
	int i = 1000;
	wskI = &i;
	cout << "wskI bez gwiazdki: " << wskI << endl;
	cout << "*wskI: " << *wskI << endl;

	//³añcuch char*:
	char *str = "Ala ma kota";
	cout << str;
}
//--------------------------------
int main()
{
	TMenu mnu;
	mnu.add("1. Cwiczenie nr 1 ze wskaznikow.");
	mnu.add("2. Opcja 2");
	unsigned int wyb = mnu.wybierz();
	switch (wyb) {
	case 1:
		zadanieNr1Wskazniki();
		break;
	case 2:
		cout << "Wybrana opcja nr 2.\n";
		break;
	default:;
	}
    return 0;
	//Cw: napisaæ wykorzystanie instancji mnu2 klasy TMenu
	//ale u¿ywaj¹c operatora new:
	TMenu *mnu2 = new TMenu();
	mnu2->add("1. Opcja 1");
	mnu2->add("2. Opcja 2");
	wyb = mnu2->wybierz();
//  alternatywnie, ale mniej elegancko:	wyb = (*mnu2).wybierz();
	delete mnu2;
}

