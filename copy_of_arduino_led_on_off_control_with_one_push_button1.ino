unsigned const LED = 8;
unsigned const BUTTON = 7;
byte lastButtonState = LOW;
byte ledState = LOW;
void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{   byte buttonState =  digitalRead(BUTTON);
 
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      ledState = (ledState == HIGH) ? LOW: HIGH;
      digitalWrite(LED, ledState);
    }
  }
 
  }
  
