# 🎙️ ESP32 Voice Assistant Satellite (I2S Audio)

Projekt inteligentnego **satelity głosowego** opartego na **ESP32-S3**, w pełni zintegrowanego z **Home Assistant Assist**. Urządzenie obsługuje Wake Word (słowo budzące), dwukierunkowe audio I2S oraz automatyczne wyciszanie multimediów podczas nasłuchiwania.

---

## 🚀 Główne Funkcje

- **Wake Word** – ciągłe nasłuchiwanie słowa kluczowego (np. „Okay Nabucasa”)
- **Dwukierunkowe audio I2S**:
  - Wejście: cyfrowy mikrofon (np. INMP441)
  - Wyjście: DAC / wzmacniacz (np. MAX98357A)
- **Automatyczne muting** multimediów podczas nasłuchiwania (`on_listening`)
- **Mixer audio** – osobne ścieżki dla ogłoszeń (TTS) i multimediów
- **Resampling** dla optymalnej jakości TTS i muzyki
- **Tryby serwisowe**: Safe Mode i Factory Reset
- **Wsparcie PSRAM** (octal) dla lepszej wydajności

---

## 🛠️ Specyfikacja Sprzętowa (Pinout)

### 🎤 Mikrofon (I2S Input)
| Pin ESP32-S3 | Funkcja          |
|--------------|------------------|
| **GPIO4**    | BCLK             |
| **GPIO3**    | LRCLK            |
| **GPIO2**    | DIN (Data In)    |

### 🔊 Głośnik (I2S Output)
| Pin ESP32-S3 | Funkcja          |
|--------------|------------------|
| **GPIO5**    | BCLK             |
| **GPIO6**    | LRCLK            |
| **GPIO7**    | DOUT (Data Out)  |

---

## 💻 Konfiguracja ESPHome

### 1. Plik `secrets.yaml`
Utwórz plik `secrets.yaml` w katalogu projektu:

```yaml
wifi_ssid: "Twoja_Nazwa_WiFi"
wifi_password: "Twoje_Haslo"
ap_ssid: "ESP32-Satellite-AP"
ap_password: "HasloAwaryjne123"