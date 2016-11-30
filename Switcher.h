#include "Arduino.h"

class Switcher {
    int buttonPin;
    char pressed; 
    
    
    //debouncing staff
    char isDebouncing;
    long debounceLastTime;  
    void checkSwitches();
    void onButtonPressed();
    void onButtonKeepsPressed();

    public:
    Switcher(int buttonPin);
    void loop();
    void setup();
};
