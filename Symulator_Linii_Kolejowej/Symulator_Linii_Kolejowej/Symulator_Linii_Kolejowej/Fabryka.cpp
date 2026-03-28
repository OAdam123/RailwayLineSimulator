/**
* Fabryka.cpp
* @brief Metoda statyczna "stworz_pojazd" klasy "Fabryka_pociagow"
* */

#include <stdexcept>
#include <memory>
#include "Fabryka.h"
#include "Klasyczne.h"
#include "Lokomotywa.h"
#include "Zespol_trakcyjny.h"

using namespace std;

unique_ptr<Pojazd> Fabryka_pociagow::stworz_pojazd(const string& typ_pociagu, Typy_oznaczen identyfikator_pojazdu) {
	if (typ_pociagu == "Klasyczne" || typ_pociagu == "klasyczne") {
		unique_ptr<Pojazd> wskaznik_na_pojazd = make_unique<Klasyczne>(identyfikator_pojazdu);
		return wskaznik_na_pojazd;
	}
	else if (typ_pociagu == "Lokomotywa" || typ_pociagu == "lokomotywa") {
		unique_ptr<Pojazd> wskaznik_na_pojazd = make_unique<Lokomotywa>(identyfikator_pojazdu);
		return wskaznik_na_pojazd;
	}
	else if (typ_pociagu == "Zespol trakcyjny" || typ_pociagu == "zespol trakcyjny") {
		unique_ptr<Pojazd> wskaznik_na_pojazd = make_unique<Zespol_trakcyjny>(identyfikator_pojazdu);
		return wskaznik_na_pojazd;
	}
	else {
		throw invalid_argument("W tym programie nie jest obslugiwany taki pojazd szynowy");
	}
}
