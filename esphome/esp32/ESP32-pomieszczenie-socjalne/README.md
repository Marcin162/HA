# ESPHome - Czujnik Garderoba (ESP32)

Projekt ESPHome dla urządzenia monitorującego warunki w garderobie na bazie ESP32.

## Funkcje

- **Pomiar temperatury i wilgotności** – DHT11
- **Pomiar temperatury za pomocą NTC** (z precyzyjnym filtrowaniem medianowym)
- **Czujnik ruchu PIR**
- **Czujnik światła** (fotorezystor)
- **Sterowanie zasilaniem czujników** (oszczędność energii)
- **Bluetooth Proxy** + BLE Tracker
- **Monitorowanie jakości sygnału WiFi**

## Schemat podłączenia

### Pinout ESP32 DevKit

| GPIO   | Komponent                  | Kierunek     | Uwagi                          |
|--------|---------------------------|--------------|--------------------------------|
| **GPIO16** | DHT11 (Data)             | Input        | Temperatura + Wilgotność       |
| **GPIO14** | PIR (OUT)                | Input        | Czujnik ruchu                  |
| **GPIO35** | Fotorezystor (ADC)       | Input        | Pomiar natężenia światła       |
| **GPIO32** | NTC (ADC)                | Input        | Pomiar temperatury NTC         |
| **GPIO27** | Zasilanie fotorezystora  | Output       | Switch – VCC                   |
| **GPIO26** | Zasilanie NTC            | Output       | Switch – włączany co 30 s      |
| **3.3V**   | DHT11 VCC, PIR VCC       | Power        | Stałe zasilanie                |
| **GND**    | Wszystkie masy           | Ground       | Wspólna masa                   |

**Dodatkowe elementy:**
- Rezystor 10 kΩ między GPIO35 a 3.3V (dla fotorezystora – konfiguracja UPSTREAM)
- Rezystor 10 kΩ między GPIO32 a 3.3V (dla NTC)

### Prosty diagram podłączenia (ASCII)

```text
                  ESP32 DevKit
               +-----------------+
               |                 |
  3.3V --------| 3.3V            |
  GND  --------| GND             |
               |                 |
  DHT11 --------| GPIO16          |
  PIR   --------| GPIO14          |
               |                 |
  Fotorezystor -| GPIO35          |--- 10kΩ --- 3.3V
               |                 |
  NTC   -------| GPIO32          |--- 10kΩ --- 3.3V
               |                 |
               | GPIO27 ---+     |  ← Zasilanie fotorezystora
               | GPIO26 ---+     |  ← Zasilanie NTC
               +-----------------+