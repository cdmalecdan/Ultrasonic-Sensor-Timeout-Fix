/*
 * Copyright 2016 (C) layadcircuits.com
 * Project: 
 * A work around fix for some ultrasonic sensors that do not timeout.
 * When there is no echo received, we set the distance to the maximum distance defined by MAX_DISTANCE_CM.
 * Author: Chris Malecadn / chris@layadcircuits.com
 * For Questions/Comments: chris@layadcircuits.com
 * Revision History:
 * 1.0 - initial commit
 */
const byte TRIGPIN = 3;
const byte ECHOPIN = 2;

const unsigned int MAX_DISTANCE_CM = 300;
float duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
}


void loop() {

  digitalWrite(TRIGPIN, LOW);  
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(20); 
  digitalWrite(TRIGPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH,50000);
  distance = (duration/2) / 29.1;
 
  if(distance == 0 && digitalRead(ECHOPIN)==HIGH)
  {
    pinMode(ECHOPIN,OUTPUT);
    digitalWrite(ECHOPIN,LOW);
    delay(10);
    pinMode(ECHOPIN,INPUT);
    distance=MAX_DISTANCE_CM;
  }
  Serial.print(distance);
  Serial.println(" cm"); 
  delay(100);
}
