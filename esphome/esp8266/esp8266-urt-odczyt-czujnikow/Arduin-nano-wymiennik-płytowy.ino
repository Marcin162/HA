#include <math.h>

#define temp1 12  /// zdefiniowanie pina pod nazwą czujni temperatury 1 NTC załanczanie napięcia
#define temp1_NTC A0 ///// Pomiar napięcia
#define zasilanie_temperatura_2 11
#define ADC_temperatura_2 A1
#define zasilanie_temperatura_3 10
#define ADC_temperatura_3 A2
#define zasilanie_temperatura_4 9
#define ADC_temperatura_4 A3
#define zasilanie_czujnik_cisnienia_1 8
#define ADC_ciscnienie_1 A4
#define zasilanie_czujnik_cisnienia_2 7
#define ADC_ciscnienie_2 A5

String odebraneDane = "";
//////////////Czujnik 1 temperatura NTC zmienne
int rezystancjia_temp1 = 0;
float R1 = 20000; //Rezystor staly 20kiloomow
float B = 3950; /// Stała materiałowa czujnika NTC
float T0 = 298.15; //Temperatura referencyjna
float R0 = 10000;  //Opornośc NTV w 25 stopniach

////////////////Czujnik 2 temperatura NTC zmienne
int rezystancja_temperatura_2 = 0;
float R1_rezystor_2 = 20000;
float B_NTC_2 = 3950;
float T0_NTC_2 = 298.15;
float R0_NTC_2 = 10000;

////////////////Czujnik 3 temperatura NTC zmienne
int rezystancja_temperatura_3 = 0;
float R1_rezystor_3 = 20000;
float B_NTC_3 = 3950;
float T0_NTC_3 = 298.15;
float R0_NTC_3 = 10000;

////////////////Czujnik 4 temperatura NTC zmienne
int rezystancja_temperatura_4 = 0;
float R1_rezystor_4 = 20000;
float B_NTC_4 = 3950;
float T0_NTC_4 = 298.15;
float R0_NTC_4 = 10000;

////////////////Czujnik Ciśnienia 1
float cisnienie_1 = 0;

////////////////Czujnik Ciśnienia2
float cisnienie_2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial1.begin(9600);
  /// Wczytanie dla 1 czujnika
  pinMode(temp1, OUTPUT);
  digitalWrite(temp1, LOW);   //LOW HIGH
  //Serial.println("Czujnik temperatury 1 off");

  /// Wczytanie dla 2 czujnika
  pinMode(zasilanie_temperatura_2, OUTPUT);
  digitalWrite(zasilanie_temperatura_2, LOW);   //LOW HIGH
  //Serial.println("Czujnik temperatury 2 off");

  /////Wczytanie dla 3 czujnika
  pinMode(zasilanie_temperatura_3, OUTPUT);
  digitalWrite(zasilanie_temperatura_3, LOW);   //LOW HIGH
  //Serial.println("Czujnik temperatury 3 off");

  /////Wczytanie dla 4 czujnika
  pinMode(zasilanie_temperatura_4, OUTPUT);
  digitalWrite(zasilanie_temperatura_4, LOW);   //LOW HIGH
  //Serial.println("Czujnik temperatury 4 off");
  
  /////////Wczytanie czujnik ciśnienia 1
  pinMode(zasilanie_czujnik_cisnienia_1, OUTPUT);
  digitalWrite(zasilanie_czujnik_cisnienia_1, LOW);   //LOW HIGH
  //Serial.println("Czujnik ciśnienia 1 off");

  /////////Wczytanie czujnik ciśnienia 2
  pinMode(zasilanie_czujnik_cisnienia_2, OUTPUT);
  digitalWrite(zasilanie_czujnik_cisnienia_2, LOW);   //LOW HIGH
  //Serial.println("Czujnik ciśnienia 2 off");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    odebraneDane = Serial.readStringUntil('\n');
    if(odebraneDane == "on")
    {
      ////////////////////////////////////////////////////////                   PIERWSZY CZUJNIK
      digitalWrite(temp1, HIGH);
      //Serial.println("Czujnik temperatury1 on");
      rezystancjia_temp1 = analogRead(temp1_NTC); //odczyt rezystancji
      //Serial.print(rezystancjia_temp1 );
      //Serial.println("bajt");
      float volt_1 = rezystancjia_temp1 * (5.0 / 1023); ///oblicznie napięcia

      //Serial.print(volt_1);
      //Serial.println(" V");
      
      float R2 = (R1 * volt_1) / (5.0 - volt_1);
      //Serial.print(R2);
      //Serial.println(" Ω");

      ///Oblicznie temperatury
      float temperatura = (log(R2 / R0) / B + 1 / T0);
      temperatura = 1 / temperatura;
      temperatura = temperatura - 273.15;
      //Serial.print("Temperatura: ");
      
      //Serial.println(" °C");

      delay(100);
      digitalWrite(temp1, LOW);
      //Serial.println("Czujnik temperatury 1 off");
      //Serial.print(",");

      /////////////////////////////////////////////////////////////////        CZUJNIK DRUGI
      digitalWrite(zasilanie_temperatura_2, HIGH);
      //Serial.println("Czujnik temperatury2 on");
      rezystancja_temperatura_2 = analogRead(ADC_temperatura_2); //odczyt rezystancji
      //Serial.print(rezystancja_temperatura_2 );
      //Serial.println("bajt");
      float volt_2 = rezystancja_temperatura_2 * (5.0 / 1023); ///oblicznie napięcia

      //Serial.print(volt_2);
      //Serial.println(" V");
      //Oblicznie oporności
      float R2_2 = (R1_rezystor_2 * volt_2) / (5.0 - volt_2);
      //Serial.print(R2_2);
      //Serial.println(" Ω");

      ///Oblicznie temperatury
      float temperatura_2 = (log(R2_2 / R0_NTC_2) / B_NTC_2 + 1 / T0_NTC_2);
      temperatura_2 = 1 / temperatura_2;
      temperatura_2 = temperatura_2 - 273.15;
      //Serial.print("Temperatura: ");
      //Serial.print(temperatura_2);
      //Serial.println(" °C");

      delay(100);
      digitalWrite(zasilanie_temperatura_2, LOW);
      //Serial.println("Czujnik temperatury 2 off");
      //Serial.print(",");

     /////////////////////////////////////////////////////////////////        CZUJNIK TRZECI
      digitalWrite(zasilanie_temperatura_3, HIGH);
      //Serial.println("Czujnik temperatury 3 on");
      rezystancja_temperatura_3 = analogRead(ADC_temperatura_3); //odczyt rezystancji
      //Serial.print(rezystancja_temperatura_3 );
      //Serial.println("bajt");
      float volt_3 = rezystancja_temperatura_3 * (5.0 / 1023); ///oblicznie napięcia

      //Serial.print(volt_3);
      //Serial.println(" V");
      //Oblicznie oporności
      float R2_3 = (R1_rezystor_3 * volt_3) / (5.0 - volt_3);
      //Serial.print(R2_3);
      //Serial.println(" Ω");

      ///Oblicznie temperatury
      float temperatura_3 = (log(R2_3 / R0_NTC_3) / B_NTC_3 + 1 / T0_NTC_3);
      temperatura_3 = 1 / temperatura_3;
      temperatura_3 = temperatura_3 - 273.15;
      //Serial.print("Temperatura: ");
      //Serial.print(temperatura_3);
      //Serial.println(" °C");

      delay(100);
      digitalWrite(zasilanie_temperatura_3, LOW);
      //erial.println("Czujnik temperatury 3 off");
      //Serial.print(",");

     /////////////////////////////////////////////////////////////////        CZUJNIK CZWARTY
      digitalWrite(zasilanie_temperatura_4, HIGH);
      //Serial.println("Czujnik temperatury 4 on");
      rezystancja_temperatura_4 = analogRead(ADC_temperatura_4); //odczyt rezystancji
      //Serial.print(rezystancja_temperatura_4 );
      //Serial.println("bajt");
      float volt_4 = rezystancja_temperatura_4 * (5.0 / 1023); ///oblicznie napięcia

      //Serial.print(volt_4);
      //Serial.println(" V");
      //Oblicznie oporności
      float R2_4 = (R1_rezystor_4 * volt_4) / (5.0 - volt_4);
      //Serial.print(R2_4);
      //Serial.println(" Ω");

      ///Oblicznie temperatury
      float temperatura_4 = (log(R2_4 / R0_NTC_4) / B_NTC_4 + 1 / T0_NTC_4);
      temperatura_4 = 1 / temperatura_4;
      temperatura_4 = temperatura_4 - 273.15;
      //Serial.print("Temperatura: ");
      //Serial.print(temperatura_4);
      //Serial.println(" °C");

      delay(100);
      digitalWrite(zasilanie_temperatura_4, LOW);
      //Serial.println("Czujnik temperatury 4 off");
      //Serial.print(",");

      ////////////////////////////////////////////////////// Czujnik cisnienia pierwszy
      digitalWrite(zasilanie_czujnik_cisnienia_1, HIGH);
      delay(100);
      //Serial.println("Czujnik ciśnienia 1 on");
      float rezytancja_cisnienie_1 = analogRead(ADC_ciscnienie_1);
      //Serial.print(rezytancja_cisnienie_1 );
      //Serial.println("bajt");
      float volt_5 = rezytancja_cisnienie_1 * (5.0 / 1023); ///oblicznie napięcia
      //Serial.print(volt_5 );
      //Serial.println("V");
      cisnienie_1 = volt_5 / 10;
      //Serial.print(cisnienie_1);
      //Serial.println(" MPa");
      
      digitalWrite(zasilanie_czujnik_cisnienia_1, LOW);
      //Serial.println("Czujnik ciśnienia off");
      //Serial.print(",");

            ////////////////////////////////////////////////////// Czujnik cisnienia drugi
      digitalWrite(zasilanie_czujnik_cisnienia_2, HIGH);
      delay(100);
      //Serial.println("Czujnik ciśnienia 2 on");
      float rezytancja_cisnienie_2 = analogRead(ADC_ciscnienie_2);
      //Serial.print(rezytancja_cisnienie_2 );
      //Serial.println("bajt");
      float volt_6 = rezytancja_cisnienie_2 * (5.0 / 1023); ///oblicznie napięcia
      //Serial.print(volt_6 );
      //Serial.println("V");
      ciscnienie_2 = volt_6 / 10;
      //Serial.println(cisnienie_2);
      //Serial.println(" MPa");
      
      digitalWrite(zasilanie_czujnik_cisnienia_2, LOW);
      //Serial.println("Czujnik ciśnienia 2 off");
      //Serial.print(",");
      //////////////////////////////////////////////////////////////////średnia logarytmiczna różnica temperatur Tlm = [(T1 - T2)]/ ln (T1/T2)
      //////// T1 = różnica temperatur na początku wymiennika
      //////////T2  = różnica temperatór na końcu wymiennika
      //////////////////Podsumowanie dane ////// czujnik temperaury 1, czujnik temperatury 2, czujnik temperatury 3, czujnik temperatury 4, czujnik ciśnienia 1, czujnik ciśnienaia2

      
      Serial.print(temperatura);
      Serial.print(",");
      Serial.print(temperatura_2);
      Serial.print(",");
      Serial.print(temperatura_3);
      Serial.print(",");
      Serial.print(temperatura_4);
      Serial.print(",");
      Serial.print(cisnienie_1);
      Serial.print(",");
      Serial.println(cisnienie_2);



    }
    if(odebraneDane == "off") 
    {
      digitalWrite(temp1, LOW);
      digitalWrite(zasilanie_temperatura_2, LOW);
      digitalWrite(zasilanie_temperatura_3, LOW);
      digitalWrite(zasilanie_temperatura_4, LOW);
      digitalWrite(zasilanie_czujnik_cisnienia_1, LOW);
      digitalWrite(zasilanie_czujnik_cisnienia_2, LOW);
      Serial.println("off");
    }
    

      //delay(5000);
  }

}
