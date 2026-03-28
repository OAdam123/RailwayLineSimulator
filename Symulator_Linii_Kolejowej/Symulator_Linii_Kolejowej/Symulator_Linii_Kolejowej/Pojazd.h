/**
* Pojazd.h
* @brief Deklaracja klasy bazowej "Pojazd", jej atrybutow oraz metod
* */
#pragma once

#include <string>

using namespace std;

/**
* @enum Warunki_pogodowe
* @brief Reprezentuje rozne warunki pogodowe
* */
enum class Warunki_pogodowe { zwykle, snieg, deszcz };

/**
* @enum Typy_oznaczen
* @brief Reprezentuje rozne typy oznaczen pociagow
* */
enum class Typy_oznaczen { Ozn_EN57, Ozn_27WEB, Ozn_TLK3221 };

/**
* @class Pojazd
* @brief Klasa bazowa reprentuj¹ca ogolny zarys pojazdu. Zawiera podstawowe atrybuty i metody, które przekazuje klasom dziedziczacym
**/ 
class Pojazd {
protected:
	Typy_oznaczen identyfikator_pojazdu; ///< identyfikator pojazdu
	double predkosc; ///< aktualna predkosc pojazdu
	double pozycja_pociagu; ///< aktualna pozycja pociagu
	int predkosc_bazowa = 1; /// <predkosc bazowa, ktora stanowi podstawe liczenia aktualnej predkosci
public:
	/**
	* @brief Konstruktor klasy "Pojazd", wywo³ywany przy tworzeniu obiektu
	* @param id_po - identyfikator pojazdu
	* */
	Pojazd(Typy_oznaczen id_po);

	/**
	* @brief Metoda zwraca identyfikator pojazdu
	* @return identyfikator_pojazdu - identyfikator pojazdu
	* */
	Typy_oznaczen get_identyfikator() const;

	/**
	* @brief Metoda zwraca aktualna pozycje pociagu
	* @return pozycja_pociagu - aktualna pozycja pociagu
	* */
	double get_pozycja_pociagu();

	/**
	* @brief Metoda zwraca aktualna predkosc
	* @return predkosc - aktualna predkosc pojazdu
	* */
	double get_predkosc();

	/**
	* @brief Metoda konwertuje identyfikator pojazdu na typ string
	* @param typ - typ oznaczenia pojazdu
	* @return mapa_typow[typ] - zmienna string reprezentujaca oznaczenie pojazdu
	* */
	string identyfikator_pojazdu_string(Typy_oznaczen typ);

	/**
	* @brief Wybiera metodê obliczania aktualnej predkosci
	* @param warunki - warunki pogodowe
	* */
	void oblicz_predkosc(Warunki_pogodowe warunki);

	/**
	* @brief Metoda czysto wirtualna, obliczajaca predkosc pojazdu w normalnych warunkach pogodowych
	* */
	virtual void obliczanie_predkosci_zwykle() = 0;

	/**
	* @brief Metoda czysto wirtualna, obliczajaca predkosc pojazdu w snieznych warunkach pogodowych
	* */
	virtual void obliczanie_predkosci_snieg() = 0;

	/**
	* @brief Metoda czysto wirtualna, obliczajaca predkosc pojazdu w deszczowych warunkach pogodowych
	* */
	virtual void obliczanie_predkosci_deszcz() = 0;

	/**
	* @brief Metoda czysto wirtualna, wyswietlajaca na ekran informacje o pojezdzie znajdujacym sie na linii kolejowej
	* */
	virtual void wyswietlacz() = 0;

	/**
	* @brief Metoda klasy bazowej, ktora zmienia wirtualne polozenie pojazdu na podstawie predkosci w kazdej iteracji programu
	* @param czas - czas, wedlug ktorego obliczana jest przemieszczanie pojazdu w danym oknie czasowym
	* */
	void nowa_pozycja(double czas);
};


