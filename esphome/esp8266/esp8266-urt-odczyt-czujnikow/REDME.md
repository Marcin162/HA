# 🔥 Inteligentny Monitor Wymiennika Płytowego (ESP8266 + Arduino Nano)

Kompleksowy system monitorowania parametrów pracy wymiennika ciepła w instalacji. Projekt wykorzystuje hybrydową architekturę: **Arduino Nano** jako precyzyjny kontroler akwizycji danych oraz **ESP8266** jako bramę komunikacyjną (Gateway) WiFi zintegrowaną z systemem **Home Assistant**.

## 🏗️ Architektura Systemu

### 1. Moduł Pomiarowy (Arduino Nano)
Odpowiada za warstwę fizyczną i precyzyjne odczyty analogowe.
* **Sensory:** 4x Termistor NTC 10K (temperatura), 2x Przetwornik ciśnienia (0-1.2 MPa).
* **Zarządzanie energią:** Zasilanie czujników jest **kluczowane** (aktywowane pinem cyfrowym tylko na 100ms podczas pomiaru). Eliminuje to błąd samonagrzewania się termistorów i oszczędza energię.
* **Komunikacja:** Moduł pracuje w trybie nasłuchu. Po otrzymaniu komendy `on`, wykonuje pomiary i wysyła odpowiedź w formacie CSV: `T1,T2,T3,T4,P1,P2\n`.

### 2. Moduł Komunikacyjny (ESP8266 / D1 Mini)
Pełni rolę inteligentnej bramy w ekosystemie **ESPHome**.
* **Logika:** Co 10 sekund odpytuje Arduino, parsuje otrzymany ciąg znaków (funkcja `sscanf`) i publikuje dane do sensorów Home Assistant.
* **Stabilność:** Zastosowano filtry typu `quantile` (0.9), które skutecznie eliminują szumy pomiarowe i zapewniają stabilne wykresy.
* **Diagnostyka:** Monitorowanie siły sygnału WiFi (dBm i %) oraz statusu połączenia z API.



## 📊 Monitorowane Parametry
- 🌡️ **4x Czujniki temperatury:** Monitoring wlotu i wylotu obu stron wymiennika płytowego.
- 💨 **2x Czujniki ciśnienia:** Kontrola ciśnienia roboczego w układzie CO i gazowym.
- 📡 **Status WiFi:** Monitoring jakości połączenia w kotłowni.

## 📐 Schemat Połączeń (Inter-Module)

| Komponent | Arduino Nano (5V) | ESP8266 (3.3V) | Opis |
| :--- | :--- | :--- | :--- |
| **Dane (TX->RX)** | Pin D1 (TX) | GPIO3 (RX) | Transmisja danych CSV |
| **Sterowanie (RX<-TX)** | Pin D0 (RX) | GPIO1 (TX) | Komendy zapytania "on/off" |
| **Zasilanie** | GND | GND | Wspólna masa (Wymagana!) |

> [!IMPORTANT]
> Przy połączeniu bezpośrednim zaleca się stosowanie dzielnika napięcia lub konwertera poziomów logicznych na linii TX(Arduino) -> RX(ESP), aby dopasować logikę 5V do standardu 3.3V.



## 🛠️ Specyfikacja Techniczna
- **Hardware:** Wemos D1 Mini + Arduino Nano.
- **Komunikacja:** UART (9600 baud, 8N1).
- **Software:** ESPHome + Home Assistant API.
- **Metoda pomiaru:** Równanie Steinharta-Harta (NTC) + liniowe mapowanie napięcia (Ciśnienie).

## 📟 Logika działania
1. **ESP8266** wysyła komendę `on\n` przez port szeregowy.
2. **Arduino Nano** zasila sensory, odczytuje wartości ADC i przelicza je na jednostki fizyczne.
3. **Arduino Nano** wysyła sformatowany ciąg znaków z powrotem do ESP.
4. **ESPHome** przetwarza dane i aktualizuje encje w dashboardzie Home Assistant.

---
**Autor:** [Marcin162](https://github.com/Marcin162)  
**Status:** Projekt aktywny - Monitorowanie kotłowni  
**Licencja:** MIT