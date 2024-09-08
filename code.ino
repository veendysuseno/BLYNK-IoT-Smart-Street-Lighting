/* IoT Project Blynk Smart Street Lighting */

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "XXXX";               // masukkan kode autentikasi disini
char ssid[] = "Veendy-Suseno";      //nama wifi
char pass[] = "Admin12345";         //password

int pinLDR = A0;
int rel = 2; // Pemilihan Pin D4
int lampuON = LOW;
int lampuOFF = HIGH;
int nilai;
int kondisi = 0;

void setup() {
    Serial.begin(9600);
    pinMode(rel, OUTPUT);
    digitalWrite(rel, lampuOFF);
    Blynk.begin(auth, ssid, pass);
    }

void loop(){
    nilai = analogRead(pinLDR);
    Serial.println(nilai);
    if (nilai < 180 && kondisi == 0){  //Apabila Cahaya Redup
        digitalWrite(rel, lampuON);
        Blynk.notify("Lampu Jalan Hidup!");
        kondisi = 1;
    }
    if (nilai > 180 && kondisi == 1){  //Apabila Cahaya Terang
        digitalWrite(rel, lampuOFF);
        Blynk.notify("Lampu Jalan Mati!");
        kondisi = 0;
    }
    Blynk.run();
}
