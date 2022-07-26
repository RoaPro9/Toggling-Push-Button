# Toggling-Push-Button
In this Arduino tutorial I will show you how to turn an LED on and off with a push button.
Whenever you press and release the button, it controls the flow of the LED. As a result, the LED will turn on the first time you release the button. It will switch off the second time., and so on.
## Arduino circuit with an LED and a button:
To build the circuit you will need those components:
### Hardware Required
- Arduino Uno R3 Board
- Breadboard
- LED – any color.
- Push button
- 220 Ohm resistor for the LED. If you don’t have this specific value, any resistor from 330 to 1k Ohm will do.
- 10k Ohm resistor for the push button. If you don’t have, you can go until 20k-50k Ohm.
- hook-up wires

### Circuit
![Copy of Arduino Led ON_OFF control with one push button](https://user-images.githubusercontent.com/70070721/180643127-451d6190-f563-42e8-8362-291a0d57219a.png)


### Arduino Code
Controlling a servo position using a potentiometer :
Create servo object to control a servo
We need to create 2 global variables, to keep the state of the button and the LED. In the loop we’ll use those variables to compare the previous state to the new state.

```C++

unsigned const LED = 8;
unsigned const BUTTON = 7;
byte lastButtonState = LOW;
byte ledState = LOW;



```
The setup function is executed once at the beginning of the program. This is the perfect time to initialize our pins with the pinMode() function:
- OUTPUT for the LED, as we’re going to write data to it.
- INPUT for the push button, as we’re going to read data from it.

```C++
void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}
```
> Now, the digital pins are correctly set up.

Create Two loops:
In the loop function, we start by reading the button’s state with the digitalRead() function and to store it inside a new local variable. 
Then we can compare the current state to the last one (from the previous execution of the loop function). 4 possibilities here:
- LOW -> LOW (last -> current).
- LOW -> HIGH.
- HIGH -> LOW.
- HIGH -> HIGH.

```C++
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
```
> Now you Start Simulation.

