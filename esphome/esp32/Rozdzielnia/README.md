# 🌡️ ESPHome Rozdzielnia - Czujniki Temperatury Podłogi

**Inteligentny monitoring temperatury podłogi w holu i korytarzu + czujnik światła w łazience**

![ESPHome](https://img.shields.io/badge/ESPHome-000000?logo=esphome&logoColor=white&style=for-the-badge)
![ESP32](https://img.shields.io/badge/ESP32-000000?logo=espressif&logoColor=white&style=for-the-badge)
![Home Assistant](https://img.shields.io/badge/Home%20Assistant-FF9800?logo=home-assistant&logoColor=white&style=for-the-badge)

---

## ✨ Funkcje

- **Dwa precyzyjne czujniki NTC** na podłodze (hol + korytarz)
- Automatyczne włączanie zasilania mostka pomiarowego tylko na czas odczytu (oszczędność energii)
- Filtry medianowe eliminujące zakłócenia
- Czujnik binarny światła w łazience (z debouncingiem)
- Pełna integracja z Home Assistant
- Tryb fallback (hotspot) w razie problemów z WiFi

---

## 📌 Schemat podłączeń

### Użyty sprzęt:
-  **Płytka**: ESP32 DevKit (board: esp32dev)
- **Czujniki**: NTC 10kΩ (B=3850)
- **Rezystory referencyjne**: 10kΩ (1% zalecane)
- **Zasilanie mostka**: 3.3V przez GPIO (z tranzystorem lub bezpośrednio)

### Pinout

| GPIO   | Funkcja                        | Kolor przewodu (sugerowany) | Uwagi |
|--------|--------------------------------|-----------------------------|-------|
| **GPIO32** | ADC1 - Hol (NTC)            | **Żółty**                   | Czujnik temperatury holu |
| **GPIO33** | ADC1 - Korytarz (NTC)       | **Zielony**                 | Czujnik temperatury korytarza |
| **GPIO12** | Zasilanie mostka Hol        | **Czerwony**                | Tylko na czas pomiaru |
| **GPIO13** | Zasilanie mostka Korytarz   | **Czerwony**                | Tylko na czas pomiaru |
| **GPIO27** | Wejście binarne (światło łazienka) | **Niebieski**        | Pull-down + debouncing |
| **GPIO14** | Switch (rezerwowy)          | -                           | Możliwe przyszłe użycie |
| **GND**    | Masa wspólna                | **Czarny**                  | Wszystkie czujniki |
| **3.3V**   | Zasilanie referencyjne      | **Czerwony**                | Do rezystorów 10kΩ |

### Schemat ideowy (tekstowy):

3.3V ──[10kΩ]── GPIO32 ──[NTC Hol]── GND
↑
GPIO12 (włączanie mostka)
3.3V ──[10kΩ]── GPIO33 ──[NTC Korytarz]── GND
↑
GPIO13 (włączanie mostka)
3.3V ──[pull-down]── GPIO27 ── Czujnik światła łazienki
text

📊 Encje w Home Assistant

Temperatura Podłogi Hol
Temperatura Podłogi Korytarz
Światło w łazience (binary_sensor)
WiFi Signal Rozdzielnia
Resistance Sensor Hol / Korytarz (opcjonalnie ukryj)


🚀 Możliwe rozszerzenia

Dodanie przekaźników do sterowania ogrzewaniem
Alarm zbyt niskiej/wysokiej temperatury
Wykresy historyczne w HA
Integracja z dashboardem podłogówki