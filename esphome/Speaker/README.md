# 🎙️ ESP32 Voice Assistant Satellite (I2S Audio)

Projekt inteligentnego satelity głosowego opartego na **ESP32**, w pełni zintegrowanego z **Home Assistant Assist**. Urządzenie obsługuje technologię **Wake Word** (słowo budzące), umożliwiając bezdotykową interakcję z inteligentnym domem.

## 🚀 Główne Funkcje
- **Obsługa Wake Word**: Ciągłe nasłuchiwanie słowa kluczowego (np. "Okay Nabucasa").
- **Dwukierunkowe Audio I2S**:
  - **Wejście**: Obsługa zewnętrznych mikrofonów cyfrowych (np. INMP441).
  - **Wyjście**: Obsługa zewnętrznych przetworników DAC/Wzmacniaczy (np. MAX98357A).
- **Automatyka wyciszania (Muting)**: System automatycznie wyłącza odtwarzacz multimedialny podczas nasłuchiwania (`on_listening`), aby uniknąć sprzężeń zwrotnych i poprawić rozpoznawanie mowy.
- **Tryby serwisowe**: Wbudowane przyciski `Safe Mode` (tryb awaryjny) oraz `Factory Reset`.

## 🛠️ Specyfikacja Sprzętowa (Pinout)

Urządzenie korzysta z dwóch magistrali I2S:

### 🎤 Mikrofon (I2S Input)
| Pin ESP32 | Funkcja |
| :--- | :--- |
| **GPIO32** | BCLK |
| **GPIO33** | LRCLK |
| **GPIO35** | DIN (Data In) |

### 🔊 Głośnik (I2S Output)
| Pin ESP32 | Funkcja |
| :--- | :--- |
| **GPIO19** | BCLK |
| **GPIO23** | LRCLK |
| **GPIO22** | DOUT (Data Out) |



## 💻 Instalacja i Konfiguracja

### 1. Przygotowanie plików
Upewnij się, że w folderze z projektem znajduje się plik `secrets.yaml` z następującymi kluczami:
```yaml
wifi_ssid: "Twoja_Nazwa_WiFi"
wifi_password: "Twoje_Haslo"
# Opcjonalnie dane dla Hotspotu (AP)
ap_ssid: "Nazwa_Hotspotu_Awaryjnego"
ap_password: "Haslo_Hotspotu"