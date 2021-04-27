#include <Servo.h>

Servo xAxis; 
Servo yAxis; 
Servo zAxis; 
Servo ghostAxis; 

int pos = 0;

void(* resetFunc) (void) = 0;

void setup() {
  xAxis.attach(6);
  yAxis.attach(9);
  zAxis.attach(11);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
 if(Serial.available()>0) 
  {
    for (pos = 130; pos >= 50; pos -= 1) { 
      ghostAxis.write(pos); 
      delay(65); 
    }
    for (pos = 0; pos <= 180; pos += 1) { 
      zAxis.write(pos); 
      delay(15); 
    }
    for (pos = 130; pos >= 50; pos -= 1) { 
      yAxis.write(pos); 
      delay(45); 
    }
    for (pos = 70; pos <= 160; pos += 1) { 
      xAxis.write(pos); 
      delay(45); 
    }
    for (pos = 130; pos >= 50; pos -= 1) { 
      ghostAxis.write(pos); 
      delay(65); 
    }
    for (pos = 160; pos >= 70; pos -= 1) { 
      xAxis.write(pos); 
      delay(45); 
    }
    for (pos = 50; pos <= 130; pos += 1) { 
      yAxis.write(pos); 
      delay(45); 
    }
    for (pos = 180; pos >= 0; pos -= 1) { 
      zAxis.write(pos); 
      delay(15); 
    }
  }  
resetFunc();
  }
