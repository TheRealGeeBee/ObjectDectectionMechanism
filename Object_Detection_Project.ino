const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int myLED = 8;
int myTrigPIN = 6;
int ECHOPin = 7;
int myServoPIN = 9; // must be a pwm pin to send signals in degrees through the servo library

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  
pinMode(myLED, OUTPUT);
//pinMode(myServoPIN, OUTPUT);
pinMode(myTrigPIN, OUTPUT);
pinMode(ECHOPin, INPUT);

digitalWrite(myLED, LOW);
//digitalWrite(myServoPIN, LOW);
//digitalWrite(myTrigPIN, LOW);

lcd.begin(16, 2);
lcd.clear();
for (int i = 0; i <= 16; i++)
{
  lcd.print(">");
  delay(200);
  }
delay(1000);
lcd.clear();
lcd.print("LOADING..");
delay(1000);
lcd.clear();
lcd.print("OBSTACLE DETECT");
lcd.setCursor(0, 1);
lcd.print("Gabriel Nnamoko");
delay(2000);
lcd.clear();

myservo.attach(9);
myservo.write(90);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(myTrigPIN, LOW);
  delayMicroseconds(5);
  digitalWrite(myTrigPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(myTrigPIN, LOW);

  float duration = pulseIn(ECHOPin, HIGH);
  float distance = (duration/2)*0.0343;

  if (distance > 400)
  {
    lcd.print("Out of Range!");
    lcd.setCursor(0, 1);
    lcd.print("Distance:");
    lcd.print(distance);
//    lcd.print("cm off");
    delay(1000);
    lcd.clear();
    }
   else if (distance >= 45 && distance <= 80)
   {
    lcd.print("Obstacle seen!");
    lcd.setCursor(0, 1);
    lcd.print("Distance:");
    lcd.print(distance);
//    lcd.print("cm off");
    digitalWrite(myLED, HIGH);
//    digitalWrite(myServoPIN, HIGH);
    myservo.write(0);
    delay(100);
    myservo.write(180);
    delay(5000);
    digitalWrite(myLED, LOW);
    myservo.write(90);
    lcd.clear();
    }
    else
    {
    lcd.clear();
    lcd.print("Distance in cm: ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    delay(1000);
//    lcd.print("cm off");
      }

}
