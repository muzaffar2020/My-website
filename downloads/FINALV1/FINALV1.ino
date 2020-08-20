#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

#include <Servo.h>
const int  buttonPin = 2;
int buttonState = 0;

Servo myservo;  
                             
int pos;                
long timeDelay;

void setup()
{
  pinMode(buttonPin, INPUT);
  myservo.attach(9);  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0); 
  lcd.print("PLS TURN OFF"); 
  lcd.setCursor(4, 1);  
  lcd.print("MACHINE!");
}

void loop()
{
  
  lcd.display();
  delay(1200);
  lcd.noDisplay();
  delay(400);
  buttonState = digitalRead(buttonPin);  
  if (buttonState == HIGH) {
    lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0); 
  lcd.print("PLS TURN OFF"); 
  lcd.setCursor(4, 1);  
  lcd.print("MACHINE!");
     for(pos = myservo.read(); pos >=0; pos -= 1) 
     {                                    
       myservo.write(pos);                        
       timeDelay = random(5, 20);
       delay(15);                                        
     }
  }
  else {
    lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0); 
  lcd.print("PLS TRY AGAIN!"); 
  
     timeDelay = random(1, 4);
     for(pos = myservo.read(); pos <=100; pos += timeDelay) 
     {                           
       myservo.write(pos);                                         
       delay(15);                                         
     }
  }
}
