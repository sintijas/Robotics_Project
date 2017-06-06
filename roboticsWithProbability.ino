#include <SoftwareSerial.h>
SoftwareSerial BT(3, 5);
String readvoice;
String previousRV;
float beliefOld; // robot's belief that he is happy
float beliefHappy;
float beliefSad;
float normalizator;
void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  previousRV = "";
  beliefOld = 0.5;
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  while (BT.available()) {
    delay(10);
    char c = BT.read();
    readvoice += c;
    //build the string- "go back", "reverse",
    //"go forward left", "go forward right",
    //"go forward", "go", "go back left",
    //"reverse left", "go back right",
    //"reverse right", "stop",
    //"start spinning","spin"
  }

  if (readvoice.length() > 0) {
    Serial.print("The command is: ");
    Serial.print(readvoice);
    Serial.print("\n");

    if (previousRV == readvoice) { // the commands are same - should be unhappy
      beliefHappy = 0.1 * beliefOld;
      beliefSad = 0.2 * (1 - beliefOld);
      normalizator = beliefHappy + beliefSad;
      beliefHappy = beliefHappy / normalizator;
      beliefSad = beliefSad / normalizator;
    }
    else {
      beliefHappy = 0.9 * beliefOld;
      beliefSad = 0.8 * (1 - beliefOld);
      normalizator = beliefHappy + beliefSad;
      beliefHappy = beliefHappy / normalizator;
      beliefSad = beliefSad / normalizator;
    }

    Serial.print("The belief is: ");
    Serial.print(beliefHappy);
    Serial.print("\n");
    
    beliefOld = beliefHappy;

    if (beliefHappy >= 0.5) {
      Serial.println("The robot is HAPPY");
      if (readvoice == "go forward" || readvoice == "go")
      {
        digitalWrite(6, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
      }
      else if (readvoice == "go forward left")
      {
        digitalWrite(6, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        delay(2000);
      }
      else if (readvoice == "go forward right")
      {
        digitalWrite(6, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(2000);
      }
      else if (readvoice == "go back" || readvoice == "reverse")
      {
        digitalWrite(6, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        delay(2000);
      }
      else if (readvoice == "go back left" || readvoice == "reverse left")
      {
        digitalWrite(6, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        delay(2000);
      }
      else if (readvoice == "go back right" || readvoice == "reverse right")
      {
        digitalWrite(6, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(2000);
      }
      else //this applies for stop and any other word
      {
        digitalWrite(6, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(2000);
      }
    }
    else { // the robot is unhappy - he spins
      Serial.println("The robot is SAD");
      digitalWrite(6, LOW);
      digitalWrite  (9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      delay(2000);
    }

    previousRV = readvoice;
    readvoice = "";

  }
}


