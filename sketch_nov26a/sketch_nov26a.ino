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
// DATA pin connected to Arduino D12
RH_ASK driver(2000, 11, 12, 10);

// Push button pins
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;

void setup() {
 Serial.begin(9600);

  // Set buttons as input with internal pull-up
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  // Initialize RF transmitter
  if (!driver.init()) {
    Serial.println("RF transmitter error");
    while (1) {}
  }

  Serial.println("RF transmitter ready");
}

// Function to send commands
void sendCommand(const char *message) {
  driver.send((uint8_t *)message, strlen(message));
  driver.waitPacketSent();

  Serial.println(message);
  delay(300);
}

void loop() {

  if (digitalRead(button1) == LOW) {
    sendCommand("1");
    while (digitalRead(button1) == LOW);
  }

  if (digitalRead(button2) == LOW) {
    sendCommand("2");
    while (digitalRead(button2) == LOW);
  }

  if (digitalRead(button3) == LOW) {
    sendCommand("3");
    while (digitalRead(button3) == LOW);
  }

  if (digitalRead(button4) == LOW) {
    sendCommand("4");
    while (digitalRead(button4) == LOW);
  }

}
