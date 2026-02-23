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
* 👉 [Zobacz szczegóły projektu](./esphome/esp32/spiker/) *(Upewnij się, że ścieżka jest poprawna)*



### 🎙️ 2. Satelita Voice Assistant (I2S)
Interaktywny asystent głosowy z obsługą słowa budzącego (Wake Word).
* **Sprzęt:** ESP32 + Mikrofon I2S + Wzmacniacz I2S.
* **Funkcje:** Bezpośrednia komunikacja głosowa z Home Assistant, inteligentne wyciszanie multimediów podczas nasłuchu.
* **Komunikacja:** I2S (Cyfrowy przesył dźwięku).
* 👉 [Zobacz szczegóły projektu](./esphome/esp32/spiker/)

### 🌡️ 3. Inteligentny Termometr Pokojowy
Podwójny pomiar temperatury dla systemów ogrzewania.
* **Sprzęt:** ESP8266 + DS18B20 + Termistor NTC (podłogowy).
* **Funkcje:** Optymalizacja zużycia energii, precyzyjne filtrowanie medianowe dla czujników analogowych.
* 👉 [Zobacz szczegóły projektu](./esphome/esp8266/esp_czujnik_temperatur/)

---

## 🛠️ Technologie i Narzędzia
- **Hardware:** ESP32, ESP8266 (Wemos D1 Mini), Arduino Nano.
- **Software:** ESPHome, Home Assistant, C++/Arduino.
- **Protokóły:** API ESPHome, I2S, UART, OneWire.

---

## 🛡️ Bezpieczeństwo
Wszystkie wrażliwe dane (hasła WiFi, klucze API) są przechowywane w pliku `secrets.yaml`, który jest ignorowany przez system kontroli wersji zgodnie z plikiem `.gitignore`.

---

**Zapraszam do kontaktu i dyskusji w zakładce [Discussions]!** *Stworzone z pasją do automatyki i czystego kodu.*