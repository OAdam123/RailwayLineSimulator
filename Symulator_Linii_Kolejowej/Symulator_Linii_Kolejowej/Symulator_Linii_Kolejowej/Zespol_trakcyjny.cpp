/**
* Zespol_trakcyjny.cpp
* @brief Konstruktor i metody wirtualne klasy dziedziczacej "Zespol_trakcyjny"
* */

#include <iostream>
#include "Zespol_trakcyjny.h"

using namespace std;

Zespol_trakcyjny::Zespol_trakcyjny(Typy_oznaczen id_po) : Pojazd(id_po) {}

void Zespol_trakcyjny::obliczanie_predkosci_zwykle() {
	predkosc = (predkosc_bazowa * 1.2) + 3;
}
void Zespol_trakcyjny::obliczanie_predkosci_snieg() {
	predkosc = (predkosc_bazowa * 1.2) + 1;
}
void Zespol_trakcyjny::obliczanie_predkosci_deszcz() {
	predkosc = (predkosc_bazowa * 1.2) + 2;
}
void Zespol_trakcyjny::wyswietlacz() {
	cout << "Pociag: Zespol trakcyjny //// Oznaczenie pociagu: " << identyfikator_pojazdu_string(identyfikator_pojazdu) << " //// Predkosc: " << predkosc * 15 << " km/h" << endl;
}
