#include <Keypad.h>

int ledPin = 8;
int warnPin = 12;

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

bool firstTime = true;
bool secondTime = true;

byte rowPins[ROWS] = {10, 9, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "";
String input = "";

void setup() {
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);
  pinMode(warnPin,OUTPUT);
  Serial.println("Setup :-");
  Serial.println("Enter security password : ");
}

void loop() {

    char key = customKeypad.getKey();

  //set up password 
  if (firstTime){
    if (key >= '0' && key <= '9'){
      password += key;
      if(password.length()==4)
      {
        firstTime = false;
        Serial.println("Password is created");
      }
    }
  }
  else
  {
    if(secondTime)
    {
      Serial.println("Enter input password : ");
      secondTime = false;
    }
    if (key >= '0' && key <= '9'){
        input+=key;
        if(input.length()==4)
        {
            if(input == password)
            {
              Serial.println("Password is correct!");
              digitalWrite(ledPin,HIGH);
              delay(5000);
              digitalWrite(ledPin,LOW);
              input="";
              secondTime = true;
            }
            else
            {
              Serial.println("Password is wrong");
              int i;
              for(i=0; i<=2; i++)
              {
                digitalWrite(warnPin,HIGH);
                delay(1000);
                digitalWrite(warnPin,LOW);
                delay(1000);
              }
              input="";
              secondTime = true;
            }
        }
        
    }
  }
}