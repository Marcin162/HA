# 🚽 Multisesnor - ESPHome 

Zaawansowany moduł monitorujący warunki środowiskowe oraz obecność. Projekt oparty na układzie **ESP8266 (D1 Mini)**, integrujący pomiary cyfrowe (I2C) i analogowe (NTC).

## 🚀 Główne Funkcje
- **Monitorowanie Atmosferyczne**: Precyzyjny pomiar temperatury i ciśnienia za pomocą czujnika **BMP280**.
- **Wirtualny Barometr**: Automatyczne obliczanie ciśnienia zredukowanego do poziomu morza (na podstawie ustawionej wysokości 555 m n.p.m.).
- **Detekcja Ruchu**: Obsługa czujnika PIR z funkcją obliczania czasu aktywności (`duty_time`).
- **Precyzyjny Pomiar NTC**: Dodatkowy pomiar temperatury z wykorzystaniem kluczowania zasilania (GPIO16), co zapobiega nagrzewaniu się termistora.

## 🛠️ Hardware (Pinout)

| Komponent | Pin ESP8266 | Opis |
| :--- | :--- | :--- |
| **BMP280 (SDA)** | GPIO4 (D2) | Magistrala I2C |
| **BMP280 (SCL)** | GPIO5 (D1) | Magistrala I2C |
| **Czujnik PIR** | GPIO15 (D8) | Detekcja ruchu (klasa: motion) |
| **NTC VCC** | GPIO16 (D0) | Kluczowanie zasilania czujnika NTC |
| **NTC Data** | A0 | Odczyt analogowy rezystancji |



## 📊 Wykorzystane Technologie (Software)
- **Kompensacja wysokości**: Lambda przeliczająca ciśnienie bezwzględne na ciśnienie na poziomie morza zgodnie ze wzorem:
  $$P_0 = P / (1 - (0.0065 \cdot h) / (T + 0.0065 \cdot h + 273.15))^{5.257}$$
- **Filtrowanie**: Zastosowano filtr medianowy dla czujnika NTC (okno 7 próbek) w celu wyeliminowania zakłóceń elektrycznych.
- **Zarządzanie czasem**: Sensor `duty_time` śledzi, jak długo w wykrywany był ruch, co pozwala na optymalizację sterowania oświetleniem lub wentylacją.

## ⚙️ Logika Pracy
Urządzenie co 60 sekund wykonuje sekwencję pomiaru NTC:
1. Włączenie zasilania czujnika (`ntc_vcc`).
2. Aktualizacja komponentu ADC (`source_sensor`).
3. Wyłączenie zasilania w celu oszczędności energii i stabilizacji odczytu.

## 📟 Instalacja
1. Upewnij się, że masz plik `secrets.yaml` z danymi WiFi.
2. Skompiluj i wgraj projekt przez ESPHome:
```bash
esphome run esp8266-multisensor.yaml

Autor: Marcin162

Status: Projekt aktywny

Lokalizacja: Łazienka Góra