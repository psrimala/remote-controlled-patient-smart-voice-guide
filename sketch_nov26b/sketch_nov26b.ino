void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
#include <RH_ASK.h>
#include <SPI.h>
#include <string.h>

// RF transmitter
RH_ASK driver(2000, 11, 12, 10);

// Push button pins
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

void setup() {
  Serial.begin(9600);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  if (!driver.init()) {
    Serial.println("RF transmitter error");
    while (1) {}
  }

  Serial.println("RF transmitter ready");
}

void sendCommand(const char *message) {
  driver.send((uint8_t *)message, strlen(message));
  driver.waitPacketSent();

  Serial.println(message);
  delay(300);
}

void loop() {

  if (digitalRead(button1) == LOW) {
