/**
* Klasyczne.cpp
* @brief Konstruktor i metody wirtualne klasy dziedziczacej "Klasyczne"
* */

#include <iostream>
#include "Klasyczne.h"

using namespace std;

Klasyczne::Klasyczne(Typy_oznaczen id_po) : Pojazd(id_po) {}

void Klasyczne::obliczanie_predkosci_zwykle() {
	predkosc = (predkosc_bazowa * 0.8) + 3;
}

void Klasyczne::obliczanie_predkosci_snieg() {
	predkosc = (predkosc_bazowa * 0.8) + 1;
}

void Klasyczne::obliczanie_predkosci_deszcz() {
	predkosc = (predkosc_bazowa * 0.8) + 2;
}

void Klasyczne::wyswietlacz() {
	cout << "Pociag: Klasyczne //// Oznaczenie pociagu: " << identyfikator_pojazdu_string(identyfikator_pojazdu) << " //// Predkosc: " << predkosc * 15 << " km/h" << endl;
}