void setup() {
  // put your setup code here, to run once:
#include <RH_ASK.>
#include <SPI.h> // Not actually used by RH_ASK, but harmless to keep
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// RF receiver
RH_ASK rf_driver;

// DFPlayer Mini
SoftwareSerial mp3Serial(10, 11); // RX, TX
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
    while (true) {
      // Halt if DFPlayer fails to initialize
    }
  }

  player.volume(20);
  Serial.println("Voice Guidance System Ready");
}

void loop() {
  uint8_t buflen = sizeof(received);

  if (rf_driver.recv((uint8_t *)received, &buflen)) {
    // En…
}
