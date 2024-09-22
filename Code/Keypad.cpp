#include <Servo.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {

{'1','2','3','A'},

{'4','5','6','B'},

{'7','8','9','C'},

{'*','0','#','D'}
};

byte rowPins[ROWS] = { 11, 10, 9, 8 };
byte colPins[COLS] = { 7, 6, 5, 4 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

Servo Lock;

int RedLED = 2;
int GreenLED = 12;

void setup()
{
  Serial.begin(9600);
  digitalWrite(RedLED, HIGH);
  digitalWrite(GreenLED, LOW);
  Lock.attach(3);
}

void loop()
{
  char customKey = keypad.getKey();
   Serial.print(customKey);
    if (customKey == '0' || customKey == '3' || customKey == '7')
    {
     Lock.write(11);
     digitalWrite(GreenLED, HIGH);
     digitalWrite(RedLED, LOW);
     delay(10000);
    }
    else 
    {
     Lock.write(90);
     digitalWrite(GreenLED, LOW);
     digitalWrite(RedLED, HIGH);
    }
  delay(50);
}

// This only semi worked for the idea I had in mind