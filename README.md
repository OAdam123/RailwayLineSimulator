[EN] - [English version](#projecttetristype-en) | [PL] - [Wersja polska](#projecttetristype-pl) 

# RailwayLineSimulator [EN]

A train movement simulator project on a railway section, implemented in **C++**. The application allows for dynamic management of various vehicle types and simulates their movement under changing weather conditions.

---

### Key Features and Functionalities

* **Advanced Class Hierarchy:** Utilization of polymorphism to handle different types of trains: **Locomotive**, **Multiple Unit**, and **Classic**.
* **Factory Design Pattern:** Implementation of the `Fabryka_pociagow` (Train Factory) class, which manages object creation using `unique_ptr` smart pointers.
* **Template Classes:** The `Odcinek_kolejowy<T>` (Railway Section) class allows handling any vehicle type while maintaining type safety.
* **Weather Condition Simulation:** The system dynamically calculates vehicle speed depending on the weather (Normal, Rain, Snow) using virtual methods.
* **"Live" Simulation:** An interactive console mode allowing real-time observation of train movement with the ability to change weather conditions during program execution.

---

### Technical Architecture

**Main Components:**
* **Pojazd (Base Class):** Defines common attributes (identifier, speed, position) and the interface for speed calculation methods.
* **Odcinek_kolejowy<T>:** A container managing a vector of vehicles (`vector<unique_ptr<T>>`), responsible for updating movement physics and rendering it in the console.
* **Fabryka_pociagow (Train Factory):** A static factory method facilitating the addition of new units to the simulation.

**Utilized C++ Mechanisms:**
* Smart pointers (`std::unique_ptr`, `std::move`) for safe memory management.
* Exception handling (`std::invalid_argument`, `std::logic_error`) in the process of adding and removing vehicles.
* Standard Template Library (STL): `vector`, `string`, `algorithm` (find_if).

---

### Technologies

* **Language:** C++
* **Standard:** ISO C++14
* **Tools:** Doxygen (for generating full technical documentation)

---
*Project developed as a practical exercise in advanced object-oriented programming and design patterns.*

---

# RailwayLineSimulator [PL]

Projekt symulatora ruchu pociągów na odcinku kolejowym, zrealizowany w języku **C++**. Aplikacja pozwala na dynamiczne zarządzanie różnymi typami pojazdów oraz symulację ich przemieszczania się w zmiennych warunkach pogodowych.

---

### Kluczowe cechy i funkcjonalności

* **Zaawansowana hierarchia klas:** Wykorzystanie polimorfizmu do obsługi różnych typów pociągów: **Lokomotywa**, **Zespół Trakcyjny** oraz **Klasyczne**.
* **Wzorzec projektowy Fabryka:** Implementacja klasy `Fabryka_pociagow`, która zarządza kreacją obiektów przy użyciu inteligentnych wskaźników `unique_ptr`.
* **Klasy szablonowe (Templates):** Klasa `Odcinek_kolejowy<T>` pozwala na obsługę dowolnego typu pojazdu, zachowując przy tym bezpieczeństwo typów.
* **Symulacja warunków pogodowych:** System dynamicznie oblicza prędkość pojazdów w zależności od aury (Zwykłe, Deszcz, Śnieg), wykorzystując metody wirtualne.
* **Symulacja "na żywo":** Interaktywny tryb konsolowy pozwalający na obserwację ruchu pociągów w czasie rzeczywistym z możliwością zmiany warunków pogodowych w trakcie działania programu.

---

### Architektura techniczna

**Główne komponenty:**
* **Pojazd (Klasa bazowa):** Definiuje wspólne atrybuty (identyfikator, prędkość, pozycja) oraz interfejs dla metod obliczania prędkości.
* **Odcinek_kolejowy<T>:** Kontener zarządzający wektorem pojazdów (`vector<unique_ptr<T>>`), odpowiedzialny za aktualizację fizyki ruchu i renderowanie go w konsoli.
* **Fabryka_pociagow:** Statyczna metoda wytwórcza ułatwiająca dodawanie nowych jednostek do symulacji.

**Wykorzystane mechanizmy C++:**
* Inteligentne wskaźniki (`std::unique_ptr`, `std::move`) dla bezpiecznego zarządzania pamięcią.
* Obsługa wyjątków (`std::invalid_argument`, `std::logic_error`) w procesie dodawania i usuwania pojazdów.
* Biblioteka standardowa (STL): `vector`, `string`, `algorithm` (find_if).

---

### Technologie

* **Język:** C++
* **Standard:** ISO C++14
* **Narzędzia:** Doxygen (do generowania pełnej dokumentacji technicznej)

---
*Projekt zrealizowany jako praktyczne ćwiczenie z zakresu zaawansowanego programowania obiektowego i wzorców projektowych.*
