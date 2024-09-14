#include <Wire.h> // include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h> // include the LiquidCrystal_I2C library for controlling the LCD


String inputs;
#define relay1 2 //Connect relay1 to Arduino pin 2
#define relay2 3 //Connect relay2 to Arduino pin 3
#define relay3 4 //Connect relay3 to Arduino pin 4


// initialize the LCD with the I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
// initialize the LCD
  lcd.begin();
  lcd.backlight();

Serial.begin(9600); //Set rate voor communicating met telefoon
pinMode(relay1, OUTPUT); //Juice
pinMode(relay2, OUTPUT); //Wodka
pinMode(relay3, OUTPUT); //Rum



}
void loop()
{
while(Serial.available()) //Check if there are available bytes to read
{
delay(10); //Delay to make it stable
char c = Serial.read(); //Conduct a serial read
if (c == '#'){
break; //Stop the loop once # is detected after a word
}
inputs += c; //Means inputs = inputs + c
}
if (inputs.length() >0)
{
Serial.println(inputs);
//For relay 1 if for more information go to 

if(inputs == "1")
{
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Gibson Reviver");
        delay(1500);
        lcd.setCursor(0, 1);
        lcd.print("wordt bereid");
        delay(3000);
        digitalWrite(relay2, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Witte Rum");
        lcd.setCursor(0, 1);
        lcd.print("TOEVOEGEN");
        delay(1000);
        digitalWrite(relay2, LOW);
        delay(1000);
        digitalWrite(relay1, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("JUICE");
        lcd.setCursor(0, 1);
        lcd.print("TOEVOEGEN");
        delay(6000);
        digitalWrite(relay1, LOW);
        lcd.clear();
        delay(1000);
}

if(inputs == "2")
{
lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Chicago");
        lcd.setCursor(0, 1);
        lcd.print("Death Neck");
        delay(3000);
        digitalWrite(relay3, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WODKA");
        lcd.setCursor(0, 1);
        lcd.print("TOEVOEGEN");
        delay(1000);
        digitalWrite(relay3, LOW);
        delay(1000);
        digitalWrite(relay1, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("JUICE");
        lcd.setCursor(0, 1);
        lcd.print("TOEVOEGEN");
        delay(6000);
        digitalWrite(relay1, LOW);
        lcd.clear();
        delay(1000);
}


inputs="";
}
}


