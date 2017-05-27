
#include <SoftwareSerial.h>

SoftwareSerial BT(3,5); //TX, RX respetively
String readvoice;

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "go back", "go forward left" ,"go forward right","go forward","go back left","go back right","stop","start spinning"
  }  
  if (readvoice.length() > 0) {
    Serial.println(readvoice);
    
  if(readvoice == "go forward")
  {
    digitalWrite(6, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    Serial.println("Works");
  }
  else if(readvoice == "go forward left")
  {
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);  
    delay(2000);
  }
  else if(readvoice == "go forward right")
  {
    digitalWrite(6, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(2000); 
  }
  else if(readvoice == "go back")
  {
    digitalWrite(6, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH); 
    delay(2000); 
  }
  else if(readvoice == "go back left")
  {
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(2000);  
  }
  else if(readvoice == "go back right")
  {
    digitalWrite(6, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW); 
    delay(2000); 
  }
  else if(readvoice == "start spinning")
  {
    digitalWrite(6, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW); 
    delay(2000); 
  }
  else //this applies for stop and any other word
  {
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(2000);
  }
 readvoice="";}} //Reset the variable

