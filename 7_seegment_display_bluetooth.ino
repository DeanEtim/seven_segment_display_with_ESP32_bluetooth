
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
String incomingMessage = "";                 // incoming message
int leds[7] = { 15, 2, 19, 21, 17, 16, 4 };  // seven-segment display pins

void setup() {
  Serial.begin(115200);
  SerialBT.begin("DEAN'S BLUETOOTH");  //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  // for (int i = 0; i < 7; i++) {
  //   pinMode(leds[i], OUTPUT);
  // }  // end for
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
  pinMode(leds[3], OUTPUT);
  pinMode(leds[4], OUTPUT);
  pinMode(leds[5], OUTPUT);
  pinMode(leds[6], OUTPUT);

  disableCore0WDT();
}  //end setup function

void display_num(int d) {
  int digit[10][7] = {
    //{A, B, C, D, E, F, G}
    //{15,2,19,21,17, 16,4}
    { 1, 1, 1, 1, 1, 1, 0 },  //0
    { 0, 1, 1, 0, 0, 0, 0 },  //1
    { 1, 1, 0, 1, 1, 0, 1 },  //2
    { 1, 1, 1, 1, 0, 0, 1 },  //3
    { 0, 1, 1, 0, 0, 1, 1 },  //4
    { 1, 0, 1, 1, 0, 1, 1 },  //5
    { 1, 0, 1, 1, 1, 1, 1 },  //6
    { 1, 1, 1, 0, 0, 0, 0 },  //7
    { 1, 1, 1, 1, 1, 1, 1 },  //8
    { 1, 1, 1, 1, 0, 1, 1 }   //9
  };

  //using ternary operator
  (digit[d][0] == 1) ? digitalWrite(leds[0], 1) : digitalWrite(leds[0], 0);  //A
  (digit[d][1] == 1) ? digitalWrite(leds[1], 1) : digitalWrite(leds[1], 0);  //B
  (digit[d][2] == 1) ? digitalWrite(leds[2], 1) : digitalWrite(leds[2], 0);  //C
  (digit[d][3] == 1) ? digitalWrite(leds[3], 1) : digitalWrite(leds[3], 0);  //D
  (digit[d][4] == 1) ? digitalWrite(leds[4], 1) : digitalWrite(leds[4], 0);  //E
  (digit[d][5] == 1) ? digitalWrite(leds[5], 1) : digitalWrite(leds[5], 0);  //F
  (digit[d][6] == 1) ? digitalWrite(leds[6], 1) : digitalWrite(leds[6], 0);  //G
}  // end display

void loop() {
  if (Serial.available()) {  // if there is something in the serial buffer
    String outGoingMessage = Serial.readString();
    SerialBT.println(outGoingMessage);
  }
  if (SerialBT.available()) {  // if there is something in the bluetooth buffer
    incomingMessage = SerialBT.readString();
    Serial.println(incomingMessage);

    if (incomingMessage == "display one" || incomingMessage == "1") {
      display_num(1);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "display two" || incomingMessage == "2") {
      display_num(2);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "display three" || incomingMessage == "3") {
      display_num(3);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "display four" || incomingMessage == "4") {
      display_num(4);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "display five" || incomingMessage == "5") {
      display_num(5);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "display six" || incomingMessage == "6") {
      display_num(6);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "display seven" || incomingMessage == "7") {
      display_num(7);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "display eight" || incomingMessage == "8") {
      display_num(8);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "display nine" || incomingMessage == "9") {
      display_num(9);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "display zero" || incomingMessage == "0") {
      display_num(0);
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "count from 0 to 9") {
      for (int n = 0; n < 10; ++n) {
        display_num(n);
        delay(1000);
      }  // end for
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "count fast" || incomingMessage == "faster") {
      for (int n = 0; n < 10; ++n) {
        display_num(n);
        delay(200);
      }  // end for
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "count slowly") {
      for (int n = 0; n < 10; ++n) {
        display_num(n);
        delay(1500);
      }  // end for
      delay(200);
      Serial.println("Done!");
    }

    else if (incomingMessage == "countdown" || incomingMessage == "initiate countdown") {
      for (int n = 9; n >= 0; --n) {
        display_num(n);
        delay(1000);
      }  // end for
      delay(200);
      Serial.println("Done!");
    }

    else {
      Serial.println("Dey Play!😂");
      Serial.println("I was not programmed to understand that, bruv!😂");
      delay(50);

      SerialBT.println("Dey Play!😂");
      delay(100);
      SerialBT.println("I was not programmed to understand that, bruv!😂");
    }
    delay(500);
  }  // end if
}  //end main loop
