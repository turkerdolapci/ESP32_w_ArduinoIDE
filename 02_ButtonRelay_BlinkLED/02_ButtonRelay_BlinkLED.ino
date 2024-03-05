/*
  02_ButtonRelay_BlinkLED

  LED blinks periodically, independent from the Relay and the Button.
  Button turns ON and OFF the Relay with an interrupt.
  Debouncing prevents the unwanted multiple input triggers from the Button.
  Number of button presses detected are printed to Serial Monitor, together with Relay state.

  GPIO0:  Button
  GPI16:  Relay
  GPIO23: LED

  turkerdolapci
*/

// define pin numbers as constant variables
// using unsigned 8 bit integer (uint8_t or byte) is reasonable, it can get integer values between 0 and 255.
const byte PIN_Button=0;
const byte PIN_Relay=16;
const byte PIN_LED=23;

// button pressing variables
uint32_t PressCount=0;

// relay state
bool RelayFlag=false;

// variables to keep track of the timing of recent interrupts
unsigned long button_time;  
unsigned long last_button_time; 

void IRAM_ATTR isr() {
  // interrupt service routine that runs with interrupt event:

  // determine the time when the button is pressed
  button_time = millis();

  // if a time longer than 250msec has passed, it is a valid press
  if (button_time - last_button_time > 250){
    
    // last counted button time
    last_button_time = button_time;

    // switch the state of the relay
    RelayFlag=!RelayFlag;
    digitalWrite(PIN_Relay, RelayFlag);     // switch the relay state

    if(RelayFlag){
      Serial.print("Relay is ON, ");
    }
    else{
      Serial.print("Relay is OFF, ");
    }

    // count the number of valid presses
    PressCount++;
    Serial.printf("Button press count: %u \n", PressCount);

  }
}

void setup() {
  // put your setup code here, to run once:

  // initialize GPIO[PIN_Button] as digital input with internal pullup
  pinMode(PIN_Button, INPUT_PULLUP);

  // initialize GPIO[PIN_Relay] and GPIO[PIN_LED] as digital output
  pinMode(PIN_Relay, OUTPUT);
  pinMode(PIN_LED, OUTPUT);

  // attach interrupt to the falling edge of the PIN_Button 
  attachInterrupt(PIN_Button, isr, FALLING);

  // start communication with serial interface with 115200 baud
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(PIN_LED, LOW);     // turn the LED off by making the voltage LOW
  delay(1000);                    // wait 1000 msec (1 sec)

  digitalWrite(PIN_LED, HIGH);    // turn the LED on by making the voltage HIGH
  delay(1000);                    // wait 1000 msec (1 sec)

}
