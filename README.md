# Symulator Linii Kolejowej

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
