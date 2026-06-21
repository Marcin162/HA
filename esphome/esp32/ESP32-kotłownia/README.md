# ESPHome - Kotłownia Monitoring (esphome-kotlownia_01)

## Opis projektu

Konfiguracja ESPHome dla urządzenia ESP32 monitorującego instalację grzewczą w kotłowni.  
Urządzenie mierzy temperatury w kluczowych punktach systemu centralnego ogrzewania oraz monitoruje pracę pompy głębinowej (studnia).

### Główne funkcje:
- Pomiar temperatury kotła za pomocą czujnika DS18B20 (OneWire)
- Pomiar temperatury w 5 punktach za pomocą czujników NTC 10kΩ (przez ADC + resistance + ntc)
  - Zasilanie podłogówki
  - Kruciec boilera
  - Zasilanie grzejników
  - Powrót podłogówki
  - Powrót grzejników
- Monitorowanie czasu pracy pompy studziennej
- Czujnik binarny stanu pompy studziennej
- Pomiar siły sygnału WiFi

## Sprzęt

### Użyte piny ESP32:

**Czujniki temperatury:**
- **GPIO13** – OneWire (Dallas DS18B20) – Temperatura kotła
- **GPIO32** – ADC – NTC Zasilanie Podłogówki
- **GPIO35** – ADC – NTC Boiler (kruciec)
- **GPIO33** – ADC – NTC Zasilanie Grzejniki
- **GPIO34** – ADC – NTC Powrót Podłogówka
- **GPIO39** – ADC – NTC Powrót Grzejniki

**Zasilanie NTC (sekwencyjne):**
- **GPIO22** – ntc_vcc (Podłogówka zasilanie)
- **GPIO25** – ntc_vcc_2 (Boiler)
- **GPIO23** – ntc_vcc_3 (Grzejniki zasilanie)
- **GPIO05** – ntc_vcc_4 (Podłogówka powrót)
- **GPIO18** – ntc_vcc_5 (Grzejniki powrót)

**Inne:**
- **GPIO27** – switch_studnia (zasilanie czujnika studni?)
- **GPIO26** – Binary sensor Studnia (wejście z pull-down)

### Schemat podłączenia NTC
Każdy czujnik NTC jest podłączony w układzie dzielnika napięcia z rezystorem 10kΩ (konfiguracja UPSTREAM).  
Zasilanie jest włączane tylko na czas pomiaru, aby zminimalizować samogrzanie i pobór prądu.

## Instalacja i konfiguracja

1. Skopiuj kod do nowego urządzenia w ESPHome (Home Assistant → ESPHome → New Device)
2. Dodaj sekrety `wifi_ssid` i `wifi_password` w pliku `secrets.yaml`
3. Skompiluj i wgrać firmware (OTA lub kabel)
4. Po pierwszym uruchomieniu urządzenie pojawi się w Home Assistant

## Encje w Home Assistant

### Sensory (Sensors):

| Nazwa | Typ | Opis |
|-------|-----|------|
| Temperatura kotła | dallas_temp | Temperatura bezpośrednio z kotła (DS18B20) |
| Rozdzielacz Podłogówki Zasilanie 1 | ntc | Temperatura zasilania podłogówki |
| Temperatura Boiler NTC kruciec | ntc | Temperatura na krucicu boilera |
| Rozdzielacz Grzejniki Zasilanie | ntc | Temperatura zasilania grzejników |
| Rozdzielacz Podlogowka Powrot | ntc | Temperatura powrotu podłogówki |
| Rozdzielacz Grzejniki Powrot | ntc | Temperatura powrotu grzejników |
| WiFi Signal Sensor Kotłownia | wifi_signal | Siła sygnału WiFi |
| Czas pracy pompy glebinowej | duty_time | Czas pracy pompy studziennej |
| Czas ostatniego uruchomienia pompy | last_time | Timestamp ostatniego startu |

### Przełączniki (Switches):
- `ntc_vcc`, `ntc_vcc_2` itd. – wewnętrzne, do sterowania pomiarem

### Binary Sensor:
- **Studnia** – stan pompy głębinowej

## Logika działania

- Co 10 sekund interwał włącza kolejno zasilanie każdego NTC, wykonuje pomiar ADC, wyłącza zasilanie.
- Filtry medianowe redukują szumy pomiarowe.
- Czujnik OneWire działa niezależnie.



## Bezpieczeństwo

- Urządzenie pracuje w kotłowni – zapewnij odpowiednie chłodzenie i ochronę przed wilgocią.
- Używaj tylko niskiego napięcia (3.3V) dla czujników.
- Sprawdź poprawność podłączenia rezystorów dzielnika napięcia.

---

**Autor:** MarcinJ  
**Data utworzenia:** czerwiec 2026  
**Wersja:** 1.0

J