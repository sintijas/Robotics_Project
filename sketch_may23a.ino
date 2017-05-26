#define E1 6 // Enable Pin for motor 1
#define E2 11 // Enable Pin for motor 2
void setup() {
  // put your setup code here, to run once
   pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
   Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
   // digitalWrite(E1, 253); // Run in full speed
    //digitalWrite(E2, 253); // Run in half speed
    digitalWrite(6, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
}
