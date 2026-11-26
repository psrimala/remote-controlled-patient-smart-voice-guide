#include <RH_ASK.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// RF receiver
RH_ASK rf_driver;

// DFPlayer Mini
SoftwareSerial mp3Serial(10, 11);
DFRobotDFPlayerMini player;

char received[20];

void setup() {
  Serial.begin(9600);

  if (!rf_driver.init()) {
    Serial.println("RF Receiver Error");
  }

  mp3Serial.begin(9600);

  if (!player.begin(mp3Serial)) {
    Serial.println("DFPlayer Error");
    while (true);
  }

  player.volume(20);

  Serial.println("Voice Guidance System Ready");
}

void loop() {
  uint8_t buflen = sizeof(received);

  if (rf_driver.recv((uint8_t *)received, &buflen)) {
    received[buflen] = '\0';
 
    Serial.println(received);

    if (strcmp(received, "1") == 0) {
      player.play(1);
    }
    else if (strcmp(received, "2") == 0) {
      player.play(2);
    }
    else if (strcmp(received, "3") == 0) {
      player.play(3);
    }
    else if (strcmp(received, "4") == 0) {
      player.play(4);
    }
    else if (strcmp(received, "5") == 0) {
      player.play(5);
    }
  }
}
