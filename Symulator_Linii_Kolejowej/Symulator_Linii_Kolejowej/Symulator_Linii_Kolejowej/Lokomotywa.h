/**
* Lokomotywa.h
* Deklaracja klasy dziedzicz¹cej "Lokomotywa" i deklaracje jej metod wirtualnych
* */

#pragma once

#include "Pojazd.h"

using namespace std;

/**
* @class Lokomotywa
* @brief Klasa dziedziczaca po klasie "Pojazd", reprezentuje typ pociagu: lokomotywa
* */
class Lokomotywa : public Pojazd {
public:
	/**
	* @brief Konstruktor klasy "Lokomotywa"
	* @param id_po - identyfikator pojazdu
	* */
	Lokomotywa(Typy_oznaczen id_po);

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
	void wyswietlacz();
};
