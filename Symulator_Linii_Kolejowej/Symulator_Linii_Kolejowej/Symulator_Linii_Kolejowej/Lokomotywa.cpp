/**
* Lokomotywa.cpp
* @brief Konstruktor i metody wirtualne klasy dziedziczacej "Lokomotywa"
* */

#include <iostream>
#include "Lokomotywa.h"

using namespace std;

Lokomotywa::Lokomotywa(Typy_oznaczen id_po) : Pojazd(id_po) {}

void Lokomotywa::obliczanie_predkosci_zwykle() {
	predkosc = (predkosc_bazowa * 1.5) + 3;
}
void Lokomotywa::obliczanie_predkosci_snieg() {
	predkosc = (predkosc_bazowa * 1.5) + 1;
}
void Lokomotywa::obliczanie_predkosci_deszcz() {
	predkosc = (predkosc_bazowa) * 1.5 + 2;
}
void Lokomotywa::wyswietlacz() {
	cout << "Pociag: Lokomotywa //// Oznaczenie pociagu: " << identyfikator_pojazdu_string(identyfikator_pojazdu) << " //// Predkosc: " << predkosc * 15 << " km/h" << endl;
}
