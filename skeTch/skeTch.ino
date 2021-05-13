/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This sketch shows how to read values from Virtual Pins

  App project setup:
    Slider widget (0...100) on Virtual Pin V1
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Ваш авторизационный токен из письма";	//Забить Ваши данные

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ваша WI-FI сеть";			//Забить Ваши данные
char pass[] = "Пароль к WIFI сети";			//Забить Ваши данные

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
 // digitalWrite(LED_BUILTIN, pinValue);
  digitalWrite(0, pinValue);
//  digitalWrite(2, !pinValue);
  // process received value
}

void setup()
{
  // Debug console
  Serial.begin(9600);
 // pinMode(LED_BUILTIN, OUTPUT); //объявляем D4 "выходным" пином
  pinMode(0, OUTPUT);
//  pinMode(2, OUTPUT);
 // digitalWrite(LED_BUILTIN, LOW);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
