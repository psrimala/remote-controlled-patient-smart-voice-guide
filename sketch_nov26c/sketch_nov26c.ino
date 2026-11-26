
#include <RH_ASK.h>
#include <SPI.h>
#include <string.h>

// RF ASK transmitter configuration
// Speed: 2000 bps
// RX pin: 11
// TX pin: 12
// PTT pin: 10

RH_ASK driver(2000, 11, 12, 10);

// Button pin configuration
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

void setup() {

  Serial.begin(9600);

  // Configure buttons
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  // Initialize RF transmitter
  if (!driver.init()) {
    Serial.println("RF Transmitter Initialization Failed!");
  } 
  else {
    Serial.println("RF Transmitter Ready!");
  }
}

// Send RF command
void sendCommand(const char *message) {

  driver.send((uint8_t *)message, strlen(message));

  driver.waitPacketSent();

  Serial.print("Command Sent: ");
  Serial.println(message);

  delay(200);
}

// Wait until button is released
void waitForRelease(int pin) {

  while (digitalRead(pin) == LOW) {
    delay(10);
  }

  delay(50);
}

void loop() {

  // Button 1
  if (digitalRead(button1) == LOW) {
    sendCommand("1");
    waitForRelease(button1);
  }

  // Button 2
  if (digitalRead(button2) == LOW) {
    sendCommand("2");
    waitForRelease(button2);
  }

  // Button 3
  if (digitalRead(button3) == LOW) {
    sendCommand("3");
    waitForRelease(button3);
  }

  // Button 4
  if (digitalRead(button4) == LOW) {
    sendCommand("4");
    waitForRelease(button4);
  }
}
