/**
* Odcinek_kolejowy.h
* @brief Deklaracja, atrubuty i metody klasy szablonowej "Odcinek_kolejowy"
* */

#pragma once

#include <iostream>
#include <stdexcept>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "pojazd.h"
#include "fabryka.h"

using namespace std;

/**
* @class Odcinek_kolejowy
* @brief Klasa szablonowa reprezentujaca odcinek kolejowy
* @tparam T - typ pojazdu obslugiwanego na odcinku kolejowym
* */
template <typename T>
class Odcinek_kolejowy {
private:
	vector<unique_ptr<T>> wektor_pojazdow; ///< Wektor przechowujacy unikalne i inteligenty wskazniki na pojazdy
public:
	/**
	* @brief Metoda dodajaca wskaznik na pojazd do wektora pojazdow, czyli do odcinka kolejowego
	* @param pojazd - wskaznik na pojazd dodawany danego typu
	* @throw invalid_argument - jesli wskaznik na pojazd jest nieprawidlowy (nullptr)
	* */
	void dodaj_pojazd(unique_ptr<T> pojazd) {
		if (pojazd) {
			wektor_pojazdow.push_back(move(pojazd));
		}
		else {
			throw invalid_argument("Nieprawidlowy pojazd");
		}
	}

	/**
	* @brief Metoda usuwajaca pojazd z odcinka kolejowego
	* @param id_do_usun - identyfikator pojazdu, ktory ma zostac usuniety
	* @throw logic_error - jesli nie mozna odnalezc pojazdu o danym oznaczeniu
	* */
	void usun_pojazd(Typy_oznaczen id_do_usun) {
		auto usuwany_pociag = find_if(wektor_pojazdow.begin(), wektor_pojazdow.end(),
			[&id_do_usun](unique_ptr<T>& pojazd) {
				return pojazd->get_identyfikator() == id_do_usun;
			});
		if (usuwany_pociag != wektor_pojazdow.end()) {
			wektor_pojazdow.erase(usuwany_pociag);
		}
		else {
			throw logic_error("Blad! Pojazd do usuniecia to nie ten sam pojazd ktory zostal wyszukany");
		}
	}

	/**
	* @brief Metoda, ktora dla kazdego pojazdu na odcinku oblicza predkosc dla danych warunkow atmosferycznych
	* @param warunki - warunki atmosferyczne
	* */
	void symulacja_pojazdow(Warunki_pogodowe warunki) {
		for (auto& pojazd : wektor_pojazdow) {
			pojazd->oblicz_predkosc(warunki);
		}
	}

	/**
	* @brief Metoda obliczajaca nowe polozenie pojazdu na odcinku oraz wyswietlajaca informacje o pojezdzie na konsole
	* @param czas - czas, wedlug ktorego obliczana jest przemieszczanie pojazdu w danym oknie czasowym
	* */
	void aktualizacja_polozenia(double czas) {
		for (auto& pojazd : wektor_pojazdow) {
			pojazd->nowa_pozycja(czas);
			pojazd->wyswietlacz();
		}
	}

	/**
	* @brief Metoda wyswietlajaca ruch pociagu na odcinku w konsoli
	* @param szerokosc_konsoli - dlugosc odcinka, na ktorym ma byc wyswietlany ruch pociagu
	* */
	void ruch_pociagu(const int szerokosc_konsoli) const {
		for (auto& pojazd : wektor_pojazdow) {
			int pozycja_aktualna = static_cast<int>(pojazd->get_pozycja_pociagu()) % szerokosc_konsoli;
			for (int i = 0; i < pozycja_aktualna; i++) {
				cout << ' ';
			}
			cout << '<' << '-' << '-' << '-' << '>' << endl;
		}
	}

	void symulacja_na_zywo() {
		Warunki_pogodowe obecne_warunki = Warunki_pogodowe::zwykle;
		const double czas_aktualizacji = 0.3;
		const int szerokosc_konsoli = 120;
		cout << "Nacisnij dowolny przycisk aby rozpoczac symulacje" << endl;
		system("pause");
		while (true) {
			if (_kbhit()) {
				char znak = _getch();
				if (znak == 'w') break;
				if (znak == 'z') obecne_warunki = Warunki_pogodowe::zwykle;
				if (znak == 's') obecne_warunki = Warunki_pogodowe::snieg;
				if (znak == 'd') obecne_warunki = Warunki_pogodowe::deszcz;
			}
			cout << "Symulacja odcinka linii kolejowej..." << endl;
			symulacja_pojazdow(obecne_warunki);
			aktualizacja_polozenia(czas_aktualizacji);
			ruch_pociagu(szerokosc_konsoli);

			cout << endl << "Nacisnij przycisk: 'w' - wyjscie z programu, 'z' - zwykle warunki pogodowe, 's' - snieg, 'd' - deszcz " << endl;
			Sleep(100);
			system("cls");
		}
	}
};

