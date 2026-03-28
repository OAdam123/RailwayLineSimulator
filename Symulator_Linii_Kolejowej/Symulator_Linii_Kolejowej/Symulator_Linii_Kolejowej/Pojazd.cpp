/**
* Pojazd.cpp
* @brief Wszystkie metody (nie liczac metod wirtualnych) klasy bazowej "Pojazd"
* */

#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include <unordered_map>
#include "Pojazd.h"

using namespace std;

Pojazd::Pojazd(Typy_oznaczen id_po) : identyfikator_pojazdu(id_po), predkosc(0.0), pozycja_pociagu(0.0) {}

Typy_oznaczen Pojazd::get_identyfikator() const {
	return identyfikator_pojazdu;
}

double Pojazd::get_pozycja_pociagu() {
	return pozycja_pociagu;
}

double Pojazd::get_predkosc() {
	return predkosc;
}

string Pojazd::identyfikator_pojazdu_string(Typy_oznaczen typ) {
	static unordered_map<Typy_oznaczen, string> mapa_typow = {
		{ Typy_oznaczen::Ozn_27WEB, "27WEB"},
		{ Typy_oznaczen::Ozn_EN57, "EN57"},
		{ Typy_oznaczen::Ozn_TLK3221, "TLK3221"}
	};
	return mapa_typow[typ];
}

void Pojazd::oblicz_predkosc(Warunki_pogodowe warunki) {
	switch (warunki) {
	case Warunki_pogodowe::zwykle:
		obliczanie_predkosci_zwykle();
		break;
	case Warunki_pogodowe::snieg:
		obliczanie_predkosci_snieg();
		break;
	case Warunki_pogodowe::deszcz:
		obliczanie_predkosci_deszcz();
		break;
	}
}

void Pojazd::nowa_pozycja(double czas) {
	pozycja_pociagu += predkosc * czas;
	if (pozycja_pociagu >= 116) {
		pozycja_pociagu = 115;
	}
}