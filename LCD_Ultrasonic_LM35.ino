#include <LiquidCrystal.h> 
int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
 const int lm35_pin = A1; 

int trigPin = 10;    // Trigger
int echoPin = 9;    // Echo
double duration, cm, inches;
 
 void setup()
 {
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
     
     Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
     void loop()
 { 
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();  
  
     
     // in cms
     lcd.setCursor(0, 0);
     lcd.print("Cm: ");
    lcd.setCursor(4, 0);
    lcd.print(cm, 1);
     

// for lm35
     int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin); /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10); /* LM35 gives output of 10mv/°C */
  
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  
  lcd.setCursor(0, 1);
     lcd.print("Celsuius: ");
    lcd.setCursor(10, 1);
    
     lcd.print(temp_val, 1);
 }
