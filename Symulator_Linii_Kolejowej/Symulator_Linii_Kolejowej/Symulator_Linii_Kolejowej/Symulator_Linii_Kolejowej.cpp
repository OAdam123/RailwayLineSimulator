/** @file */

/**
* Symulator_Linii_Kolejowej.cpp
* @brief Plik main programu "Symulator Linii Kolejowej, z poziomu ktorego mozna sterowac calym programem
* */

#include "Pojazd.h"
#include "Odcinek_kolejowy.h"
#include "Fabryka.h"


using namespace std;

int main() {
	try {
		/// tworzenie obiektu klasy "Odcinek_kolejowy", po ktorym beda poruszac sie pociagi
		Odcinek_kolejowy<Pojazd> odcinek1;
		/// wywolanie metody "dodaj_pojazd", dodajacej wybrany typ pojazdu na odcinek
		odcinek1.dodaj_pojazd(Fabryka_pociagow::stworz_pojazd("Klasyczne", Typy_oznaczen::Ozn_27WEB));
		odcinek1.dodaj_pojazd(Fabryka_pociagow::stworz_pojazd("Zespol trakcyjny", Typy_oznaczen::Ozn_EN57));
		odcinek1.dodaj_pojazd(Fabryka_pociagow::stworz_pojazd("Lokomotywa", Typy_oznaczen::Ozn_TLK3221));
		odcinek1.dodaj_pojazd(Fabryka_pociagow::stworz_pojazd("Zespol trakcyjny", Typy_oznaczen::Ozn_27WEB));
		odcinek1.dodaj_pojazd(Fabryka_pociagow::stworz_pojazd("Lokomotywa", Typy_oznaczen::Ozn_TLK3221));
		/// wywolanie metody "usun_pojazd", ktora usuwa pojazd wedlug identyfikatora
		//odcinek1.usun_pojazd(Typy_oznaczen::Ozn_27WEB);
		//odcinek1.usun_pojazd(Typy_oznaczen::Ozn_27WEB);
		/// wywolanie metody "symulacja_na_zywo", przedstawia wirtualny ruch pociagow po odcinku
		odcinek1.symulacja_na_zywo();
	}
	catch (const exception& blad) {
		cerr << "Rodzaj bledu: " << blad.what() << endl;
	}
	return 0;
}