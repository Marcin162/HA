# 🏠 Marcin162 - Home Assistant & ESPHome Projects

Witaj w moim repozytorium projektów inteligentnego domu! Znajdziesz tutaj kompletne rozwiązania oparte na ekosystemie **ESPHome**, które integrują urządzenia oparte na ESP8266, ESP32 oraz Arduino z systemem **Home Assistant**.

---

## 🚀 Moje Projekty

Poniżej znajduje się lista aktywnych projektów podzielona na kategorie. Każdy folder zawiera szczegółową dokumentację techniczną oraz schematy połączeń.

### 1. 🔥 Monitor Wymiennika Płytowego (Gaz)
Zaawansowany system monitorowania kotłowni oparty na współpracy dwóch mikrokontrolerów.
* **Sprzęt:** Arduino Nano (Akwizycja danych) + ESP8266 (Gateway WiFi).
* **Funkcje:** Pomiar 4 temperatur NTC oraz 2 ciśnień (MPa) z precyzyjnym kluczowaniem zasilania czujników.
* **Komunikacja:** UART (Protokół CSV).
* 👉 [Zobacz szczegóły projektu](./esphome/esp8266/esp8266-urt-odczyt-czujnikow/) 



### 🎙️ 2. Satelita Voice Assistant (I2S)
Interaktywny asystent głosowy z obsługą słowa budzącego (Wake Word).
* **Sprzęt:** ESP32 + Mikrofon I2S + Wzmacniacz I2S.
* **Funkcje:** Bezpośrednia komunikacja głosowa z Home Assistant, inteligentne wyciszanie multimediów podczas nasłuchu.
* **Komunikacja:** I2S (Cyfrowy przesył dźwięku).
* 👉 [Zobacz szczegóły projektu](./esphome/esp32/Speaker/)

### 🌡️ 3. Inteligentny Termometr Pokojowy
Podwójny pomiar temperatury dla systemów ogrzewania.
* **Sprzęt:** ESP8266 + DS18B20 + Termistor NTC (podłogowy).
* **Funkcje:** Optymalizacja zużycia energii, precyzyjne filtrowanie medianowe dla czujników analogowych.
* 👉 [Zobacz szczegóły projektu](./esphome/esp8266/esp8266-sensor-ntc-ha/)

### 🌡️ 4. Multisensor Środowiskowy 
Wielofunkcyjny moduł monitorujący warunki w pomieszczeniu oraz obecność domowników.
* **Sprzęt:** ESP8266 (D1 Mini) + BMP280 + PIR + NTC.
* **Funkcje:** Pomiar temperatury i ciśnienia (z przeliczeniem na poziom morza - 555m n.p.m.), detekcja ruchu z licznikiem czasu aktywności (`duty_time`).
* **Innowacja:** Kluczowanie zasilania NTC przez GPIO dla maksymalnej precyzji odczytu.
* 👉 [Zobacz szczegóły projektu](./esphome/esp8266/Multisensor/)

### ☀️ 5. Sterownik Solarny PWM
System zarządzania kolektorem słonecznym z dynamiczną regulacją przepływu (ESP32 + Arduino).
**Sprzęt:** ESP32 + NTC
**Funkcje** Pomiar temperatury, komunikacja  URT

### 🔥 6. Sterownik Kotła OpenTherm (Termo Control)
Mój najbardziej zaawansowany projekt sterowania ogrzewaniem.
* **Sprzęt:** ESP8266 + OpenTherm Shield.
* **Funkcje:** Pełna modulacja palnika, diagnostyka błędów, statystyki pracy kotła.
* 👉 [Zobacz szczegóły projektu](./esphome/esp8266/Termo_Control/)
---

## 🛠️ Technologie i Narzędzia
- **Hardware:** ESP32, ESP8266 (Wemos D1 Mini), Arduino Nano.
- **Software:** ESPHome, Home Assistant, C++/Arduino.
- **Protokóły:** API ESPHome, I2S, UART, OneWire.
- **Algorytmy:** Przeliczanie ciśnienia barometrycznego, filtry medianowe, sscanf UART parsing.

---

## 🛡️ Bezpieczeństwo
Wszystkie wrażliwe dane (hasła WiFi, klucze API) są przechowywane w pliku `secrets.yaml`, który jest ignorowany przez system kontroli wersji zgodnie z plikiem `.gitignore`.

---

**Zapraszam do kontaktu i dyskusji w zakładce [Discussions]!** *Stworzone z pasją do automatyki i czystego kodu.*