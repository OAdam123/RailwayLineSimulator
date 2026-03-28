/**
* Zespol_trakcyjny.h
* @brief Deklaracja klasy dziedzicz¹cej "Zespol_trakcyjny" i deklaracje jej metod wirtualnych
* */
#pragma once

#include "Pojazd.h"

using namespace std;

/**
* @class Zespol_trakcyjny
* @brief Klasa dziedziczaca po klasie "Pojazd", reprezentuje typ pociagu: zespol trakcyjny
* */
class Zespol_trakcyjny : public Pojazd {
public:
	/**
	* @brief Konstruktor klasy "Zespol_trakcyjny"
	* */
	Zespol_trakcyjny(Typy_oznaczen id_po);

	/**
	* @brief Metoda wirtualna, obliczajaca predkosc pojazdu w normalnych warunkach pogodowych. Przyjmuje wartosc bazowa i wedlug prostych operacji arytmetycznych oblicza aktualna predkosc pojazdu
	**/
	void obliczanie_predkosci_zwykle() override;

	/**
	* @brief Metoda wirtualna, obliczajaca predkosc pojazdu w snieznych warunkach pogodowych. Przyjmuje wartosc bazowa i wedlug prostych operacji arytmetycznych oblicza aktualna predkosc pojazdu
	**/
	void obliczanie_predkosci_snieg() override;

	/**
	* @brief Metoda wirtualna, obliczajaca predkosc pojazdu w deszczowych warunkach pogodowych. Przyjmuje wartosc bazowa i wedlug prostych operacji arytmetycznych oblicza aktualna predkosc pojazdu
	**/
	void obliczanie_predkosci_deszcz() override;

	/**
	* @brief Metoda wirtualna, wyswietla na ekran informacje o danym pojezdzie znajdujacym sie na odcinku kolejowym
	* */
	void wyswietlacz() override;
};
