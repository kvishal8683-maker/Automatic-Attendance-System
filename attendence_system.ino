#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {A0,A1,A2,A3};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int buzzer = 10;
String inputID = "";

void setup() {
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
  lcd.print("Enter ID:");
  lcd.setCursor(0,1);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      lcd.clear();

      if (inputID == "1234" || inputID == "5678") {
        lcd.print("Attendance");
        lcd.setCursor(0,1);
        lcd.print("Marked");
        tone(buzzer, 1000, 500);
      }
      else {
        lcd.print("Invalid ID");
        tone(buzzer, 500, 1000);
      }

      delay(2000);
      inputID = "";
      lcd.clear();
      lcd.print("Enter ID:");
      lcd.setCursor(0,1);
    }
    else if (key == '*') {
      inputID = "";
      lcd.clear();
      lcd.print("Enter ID:");
      lcd.setCursor(0,1);
    }
    else {
      inputID += key;
      lcd.print("*");
    }
  }
}