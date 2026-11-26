#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// DFPlayer communication
SoftwareSerial mp3Serial(10, 11);
DFRobotDFPlayerMini player;

// RF receiver pins
const int waterButton = 4;
const int foodButton = 5;
const int medicineButton = 6;
const int helpButton = 7;

// Emergency button
const int emergencyButton = 8;

// Previous button states
int previousWater = LOW;
int previousFood = LOW;
int previousMedicine = LOW;
int previousHelp = LOW;
int previousEmergency = HIGH;

void setup() {

  Serial.begin(9600);
  mp3Serial.begin(9600);

  pinMode(waterButton, INPUT);
  pinMode(foodButton, INPUT);
  pinMode(medicineButton, INPUT);
  pinMode(helpButton, INPUT);

  pinMode(emergencyButton, INPUT_PULLUP);

  Serial.println("Smart Voice Guider Startin…void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
