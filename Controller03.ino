#include "dimmer_types.h"
#include "simple_switcher.h"


//детская Ани
SimpleSwitcher sd1(A0, A4);
//детская Мальчиков
SimpleSwitcher sd2(A2, A5);
//Лоджия
SimpleSwitcher sd3(8, 13);
//Гардеробная
SimpleSwitcher sd4(11, 12);


 
void setup() 
{
  sd1.setup();
  sd2.setup();
  sd3.setup();
  sd4.setup();
}
 
void loop() 
{
    sd1.loop();
    sd2.loop();
    sd3.loop();
    sd4.loop();
}
