# ESPHome - Schody Oświetlenie (ESP8266 D1 Mini Lite)

## Opis projektu

Prosta konfiguracja ESPHome na płytce **ESP8266 D1 Mini Lite** służąca do sterowania oświetleniem na schodach.  
Urządzenie działa jako przełącznik + raportuje jakość sygnału WiFi do Home Assistant.

### Główne funkcje:
- Sterowanie oświetleniem schodów za pomocą przekaźnika / triaka / MOSFET-a na pinie GPIO5
- Monitorowanie siły sygnału WiFi (w dB i w %)
- Fallback hotspot (captive portal) na wypadek problemów z WiFi
- Szyfrowana komunikacja z Home Assistant

## Sprzęt

- **Płytka:** ESP8266 D1 Mini Lite
- **Pin sterujący:** **GPIO5** – wyjście na oświetlenie schodów (`schody_oswietlenie`)
- Zalecane użycie: przekaźnik 5V lub moduł SSR (Solid State Relay) dla bezpieczeństwa

## Instalacja i konfiguracja

1. Skopiuj kod do nowego urządzenia w ESPHome.
2. Uzupełnij sekrety w pliku `secrets.yaml`:
   
---
**Autor:** [Marcin162](https://github.com/Marcin162)  
**Status:** Projekt aktywny - Monitorowanie kotłowni  
**Licencja:** MIT