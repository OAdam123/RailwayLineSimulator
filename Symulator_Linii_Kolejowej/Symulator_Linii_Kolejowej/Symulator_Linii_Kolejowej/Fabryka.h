/**
* Fabryka.h
* @brief Deklaracja klasy "Fabryka_pociagow" i deklaracja jej funkcji statycznej
* */

#pragma once

#include <string>
#include "Pojazd.h"

using namespace std;

/**
* @class Fabryka_pociagow
* @brief Klasa, w ktorej "produkowane" sa nowe pociagi roznego typu
* */
class Fabryka_pociagow {
public:
	/**
	* @brief Metoda statyczna, ktora tworzy i przypisuje danemu pojazdowi oznaczenie
	* @param typ_pociagu - zmienna string zawierajaca nazwe typu pociagu, ktory chcemy utworzyc
	* @param identyfikator_pojazdu - typ oznaczenia pojazdu
	* @throw invalid_argument - jesli do parametru wpisany jest niezdefiniowany typ pojazdu
	* @return wskaznik_na_pojazd - inteligentny wskaznik unique_ptr ktory wskazuje na nowo-utworzony pojazd
	* */
	static unique_ptr<Pojazd> stworz_pojazd(const string& typ_pociagu, Typy_oznaczen identyfikator_pojazdu); 
};
