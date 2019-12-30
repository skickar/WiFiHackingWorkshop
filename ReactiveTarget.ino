// SIMPLE Wi-FI LINK MONITOR BY SKICKAR - Based on Henry's Bench Wi-Fi link checker
// This project has the goal to connect an ioT device to a Wi-Fi network and monitor the ability to establish a normal wireless connection.
// The project uses only three componants - A nodeMCU, a breadboard, and one RGB LED.
    #include <ESP8266WiFi.h> // First, we include the libraries we need to make this work on the ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

    const char* ssid     = "Control"; // Next, we set the name of the network to monitor.
    const char* password = "testytest"; // After that, we enter the password of the network to monitor.
    int wifiStatus; // Here, we create a variable to check the status of the Wi-Fi connection.
    int connectSuccess = 0, highTime = 500, lowtime = 500; // And now, we set a variable to count the number of times we've been able to successfully connect, and how long the LED will stay on and off for.

void red() { // Here, we will map a function called "red" to the right pin that will light up the red LED for the amount of time we defined in hightTime for how long it is lit, and lowTime for how long it is off each time we pulse a red LED.
      digitalWrite(D1, HIGH), delay(highTime), digitalWrite(D1, LOW), delay(lowtime);  // We map the red function to the D5 pin, so that each time we call red() it will pulse power on the D5 pin.
}
void green() { // We do the same with green, mapping the D6 pin to the green() function.
      digitalWrite(D2, HIGH), delay(highTime), digitalWrite(D2, LOW), delay(lowtime);
}
void blue() { // Finally, we do the same with blue, mapping it to the D7 pin.
      digitalWrite(D3, HIGH), delay(highTime), digitalWrite(D3, LOW), delay(lowtime);
}
void setup() { // The setup function runs only once when the device starts up.
  unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

  pinMode(D1, OUTPUT), pinMode(D2, OUTPUT), pinMode(D3, OUTPUT); // In this case, we will activate the D5, D6, and D7 pins for output mode.
      WiFi.begin(ssid, password); // The last part of setup we will write is to start the Wi-Fi connection process.
      }

void loop() { // This loop will run over and over again, unlike the setup function, which will only run once.
          HTTPClient http;
          http.begin(/*client, */ "http://192.168.4.1");

        int httpCode   = http.GET();
        String payload = http.getString();

        if (httpCode > 0) {
        } else {
            Serial.printf("ERROR %d\n", httpCode);
        }



     
      //delay(1000); // Set a delay of one second per cycle of checking the status of the link.
      wifiStatus = WiFi.status(); // First, we'll check the status of the Wi-Fi connection and store the result in the variable we created, wifiStatus.
      if(connectSuccess == 0){ blue();} // If device is not connected and never has successfully connected, flash the blue light. This could mean the network doesn't exist, is out of range, or you misspelled the SSID or password.
      if(wifiStatus == WL_CONNECTED){ green(), connectSuccess ++; } // If the device is connected, flash the green light, and add one to the count of the "connectSuccess" variable. This way, we will know to flash the red light if we lose the connection.
      else if(connectSuccess != 0){ red(); } // If the connection is not active but we have been able to connect before, flash the red LED. That means the AP is down, a jamming attack is in progress, or a normal link is otherwise impossible.
      
}
