#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// порты для подключения модуля ULN2003 к Arduino
#define in1 8
#define in2 9
#define in3 10
#define in4 11

#define in5 4
#define in6 5
#define in7 6
#define in8 7


LiquidCrystal_I2C lcd(0x27,16,2);
int piezo = 3;
int x;
int dl = 3; // время задержки между импульсами
 
void setup() { 
	Serial.begin(115200); 
	Serial.setTimeout(1);

  lcd.init();
  lcd.backlight();

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);

  tone(piezo, 300, 200);
  delay(300);
  tone(piezo, 600, 300);
  delay(600);
  tone(piezo, 1000, 400);
  delay(800);
  lcd.print("Privet!");
  lcd.setCursor(0,1);
  lcd.print("Ya Senya!");
  Serial.println("Privet! Ya Senya!");
  Serial.println("Nachnem!");
  delay(1000);
  lcd.clear();
  lcd.print("Nachnem)))");
  delay(1000);  
}

void loop() { 
  unsigned char ch;
	if (Serial.available()){
    x = 50;
    ch = Serial.read();
    if (ch=='l') {
      while (x>0) {
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, HIGH);
      delay(dl);
      
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, LOW);
      delay(dl);
      
      digitalWrite(in1, LOW); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
      delay(dl);

      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, HIGH);
      delay(dl);
      x--;
      }
      lcd.clear();
      lcd.print("Left OK!");
      Serial.println("Left OK!");
    }

    if (ch=='r') {
      while (x>0) {
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, HIGH);
      delay(dl);
      
      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, HIGH);
      delay(dl);
      
      digitalWrite(in1, LOW); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
      delay(dl);

      digitalWrite(in1, HIGH); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, LOW);
      delay(dl);
      x--;
      }
      lcd.clear();
      lcd.print("Right OK!");
      Serial.println("Right OK!");
    }

    if (ch=='u') {
      while (x>0) {
      digitalWrite(in5, HIGH); 
      digitalWrite(in6, LOW); 
      digitalWrite(in7, LOW); 
      digitalWrite(in8, HIGH);
      delay(dl);
      
      digitalWrite(in5, HIGH); 
      digitalWrite(in6, HIGH); 
      digitalWrite(in7, LOW); 
      digitalWrite(in8, LOW);
      delay(dl);
      
      digitalWrite(in5, LOW); 
      digitalWrite(in6, HIGH); 
      digitalWrite(in7, HIGH); 
      digitalWrite(in8, LOW);
      delay(dl);

      digitalWrite(in5, LOW); 
      digitalWrite(in6, LOW); 
      digitalWrite(in7, HIGH); 
      digitalWrite(in8, HIGH);
      delay(dl);
      x--;
      }
      lcd.clear();
      lcd.print("Up OK!");
      Serial.println("Up OK!");
    }

    if (ch=='d') {
      while (x>0) {
      digitalWrite(in5, HIGH); 
      digitalWrite(in6, LOW); 
      digitalWrite(in7, LOW); 
      digitalWrite(in8, HIGH);
      delay(dl);
      
      digitalWrite(in5, LOW); 
      digitalWrite(in6, LOW); 
      digitalWrite(in7, HIGH); 
      digitalWrite(in8, HIGH);
      delay(dl);
      
      digitalWrite(in5, LOW); 
      digitalWrite(in6, HIGH); 
      digitalWrite(in7, HIGH); 
      digitalWrite(in8, LOW);
      delay(dl);

      digitalWrite(in5, HIGH); 
      digitalWrite(in6, HIGH); 
      digitalWrite(in7, LOW); 
      digitalWrite(in8, LOW);
      delay(dl);
      x--;
      }
      lcd.clear();
      lcd.print("Down OK!");
      Serial.println("Down OK!");
    }
  }
  }     