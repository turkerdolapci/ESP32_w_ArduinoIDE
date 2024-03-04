/*
  01_Blink_Relay_LED

  This example turns ON and OFF the LED and the Relay alternatingly included in the 
  LCTECH ESP32 SINGLE RELAY MODULE X1 Development Board.

  GPIO16:  Relay
  GPIO23:  LED

  turkerdolapci
*/

// define pin numbers as constant variables
// using unsigned 8 bit integer (uint8_t or byte) is reasonable, it can get integer values between 0 and 255.
const byte PIN_Relay=16;
const byte PIN_LED=23;

void setup() {
  // put your setup code here, to run once:

  // initialize digital GPIO[PIN_Relay] and GPIO[PIN_LED] as output
  pinMode(PIN_Relay, OUTPUT);
  pinMode(PIN_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(PIN_Relay, HIGH);  // turn the Relay on by making the voltage HIGH
  digitalWrite(PIN_LED, LOW);     // turn the LED off by making the voltage LOW
  delay(1000);                    // wait 1000 msec (1 sec)

  digitalWrite(PIN_Relay, LOW);   // turn the Relay off by making the voltage LOW
  digitalWrite(PIN_LED, HIGH);    // turn the LED on by making the voltage HIGH
  delay(1000);                    // wait 1000 msec (1 sec)

}
