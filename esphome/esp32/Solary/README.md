# ☀️ ESP32 Solar Controller (Differential Temperature)

Zaawansowany sterownik solarny oparty na **ESP32**, optymalizujący proces podgrzewania wody użytkowej (CWU) poprzez inteligentne sterowanie różnicowe.

## 🧠 Zasada Działania
System mierzy temperaturę w dwóch punktach: na kolektorze słonecznym oraz w boilerze. Na podstawie różnicy temperatur (**Delta T**), ESP32 decyduje o uruchomieniu pompy obiegowej oraz przesyła dane do podrzędnego sterownika Arduino w celu precyzyjnej regulacji mocy pompy przez **PWM**.

## 🚀 Funkcje
- **Logika Delta T**: Pompa pracuje tylko wtedy, gdy słońce realnie dogrzewa wodę.
- **Kluczowanie NTC**: Sensory NTC są zasilane tylko w momencie odczytu (eliminacja błędu samonagrzewania).
- **Integracja UART**: Komunikacja z Arduino Nano w celu sterowania silnikiem pompy.
- **Zabezpieczenia**: 
  - Automatyczny start przy > 80°C na solarze (ochrona kolektora).
  - Histereza zapobiegająca "taktowaniu" pompy.



## 🔌 Hardware
- **Kontroler**: ESP32 DevKit V1.
- **Sensory**: 2x NTC 10k (Kolektor + Boiler).
- **Komunikacja**: UART (9600 baud) do modułu wykonawczego.

## 📊 Dashboard Home Assistant
Urządzenie udostępnia encje:
- **Temperatura Solar / Boiler**: Podgląd na żywo.
- **Delta temperatury**: Różnica potencjałów cieplnych.
- **Przełącznik "Pompa solarna"**: Tryb manualny/automatyczny.
- **Suwak Delta**: Możliwość zdalnej korekty progu startu pompy z poziomu aplikacji.

---
**Autor:** [Marcin162](https://github.com/Marcin162)  
**Status:** Wdrożenie - System grzewczy  
**Licencja:** MIT