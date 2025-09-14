#include <string>

const String letters_morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                    "-----"  , ".----"  , "..---"  , "...--"  , "....-" , "....." , "-...."  , "--..." , "---.." , "----."};// Morse letters (26) followed by numbers(10)
const String letters_normal[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9"};
String letter = "";
const int time_unit_ms = 150;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  if (digitalRead(2) == 1) {
    unsigned long start1 = millis();
    while (digitalRead(2) == 1) {
      //just wasting time here
    }
    unsigned long stop1 = millis();
    unsigned long duration1 = stop1 - start1;
    if (duration1 < time_unit_ms) {
      letter = letter + ".";
    }
    else if (duration1 > time_unit_ms && duration1 < 3 * time_unit_ms) {
      letter = letter + "-";
    }
  }
  else if (digitalRead(2) == 0) {
     unsigned long start2 = millis();
    while (digitalRead(2) == 0) {
      //time wasting 2: the sequel
    }
    unsigned long stop2 = millis();
    unsigned long duration2 = stop2 - start2;
    if (duration2 > 3 * time_unit_ms) {
      Serial.println(letter);
      letter = "";
    }
  }
}