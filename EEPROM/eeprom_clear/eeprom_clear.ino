#include <EEPROM.h>

void setup() {
  // initialize the LED pin as an output
  pinMode(13, OUTPUT);

  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }

  // turn the LED on when we're done
  digitalWrite(13, HIGH);
}

void loop() {
  /** Empty loop. **/
}
