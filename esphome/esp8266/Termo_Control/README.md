# 🔥 OpenTherm Gas Boiler Controller (Termo Control)

Zaawansowany interfejs sterowania kotłem gazowym wykorzystujący protokół **OpenTherm**. Projekt umożliwia pełną integrację pieca z **Home Assistant**, dając wgląd w parametry diagnostyczne oraz możliwość precyzyjnej modulacji mocy grzewczej.

## 🚀 Główne Możliwości
- **Pełna Diagnostyka**: Odczyt temperatury wody zasilającej, powrotnej, CWU oraz spalin.
- **Precyzyjne Sterowanie**: Ustawianie temperatury wody grzewczej (modulacja) oraz temperatury zasobnika CWU.
- **Bezpieczeństwo**: Monitorowanie błędów kotła (brak płomienia, niskie ciśnienie wody, przegrzanie).
- **Statystyki**: Licznik godzin pracy palnika, pompy oraz liczba cykli startowych.



## 🛠️ Specyfikacja Sprzętowa
- **Kontroler**: Wemos D1 Mini (ESP8266).
- **Interfejs**: Shield OpenTherm (konwerter poziomów napięć).
- **Pinout**:
  - **D2 (GPIO4)**: Input (In_pin)
  - **D1 (GPIO5)**: Output (Out_pin)

## 📊 Kluczowe Encje w Home Assistant
Urządzenie udostępnia ponad 30 sensorów i przełączników, w tym:
- **Sensory**: Poziom modulacji palnika (%), ciśnienie w układzie (bar), prąd jonizacji płomienia (μA).
- **Przełączniki**: Włącznik ogrzewania CO, włącznik grzania wody użytkowej.
- **Liczby (Numbers)**: Nastawa temperatury zasilania oraz krzywa grzewcza (OTC).

## ⚙️ Konfiguracja i Logi
Projekt korzysta z rozbudowanego logowania (`VERBOSE`), co pozwala na debugowanie ramek danych przesyłanych magistralą OpenTherm bezpośrednio w konsoli ESPHome.

## ⚠️ Ważna Uwaga
Prace przy instalacjach gazowych wymagają ostrożności. Upewnij się, że Twój kocioł wspiera standard OpenTherm (większość nowoczesnych kotłów m.in. Viessmann, Vaillant, Baxi, Junkers).

---
**Autor:** [Marcin162](https://github.com/Marcin162)  
**Status:** Projekt produkcyjny - Zarządzanie energią  
**Licencja:** MIT