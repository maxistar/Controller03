#ifndef SWITCHER_H
#define SWITCHER_H
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "Switcher.h"

#define DEBOUNCE 50

Switcher::Switcher(int buttonPin){
    this->buttonPin = buttonPin;
} 

void Switcher::setup(){
    pinMode(this->buttonPin, INPUT_PULLUP);
} 


void Switcher::checkSwitches()
{
    if (this->isDebouncing && (this->debounceLastTime + DEBOUNCE) > millis()) {
        return; // not enough time has passed to debounce
    }
    char buttonState = digitalRead(this->buttonPin);
    char currentState = !buttonState;   // read the button

    if (currentState != this->pressed) {
        if (currentState == 1) {
            // just pressed
            this->onButtonPressed();
            this->pressed = 1;
        }
        else {
            // just released
            this->pressed = 0;
        }
        this->isDebouncing = 1;
    } 
    else {
        this->isDebouncing = 0; 
    }
    // ok we have waited DEBOUNCE milliseconds, lets reset the timer
    this->debounceLastTime = millis();
}

void Switcher::loop() {
    this->checkSwitches();      // when we check the switches we'll get the current state 
}

void Switcher::onButtonPressed() {
    
}

#endif

