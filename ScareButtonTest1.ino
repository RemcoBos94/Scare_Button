
#include <DmxSimple.h>

const byte dmxTransmitPin = 3;
// Used to switch between Master/Slave modes
const byte modeSelectPin = 2;
const int buttonPin = 2;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
    DmxSimple.usePin(dmxTransmitPin);
    DmxSimple.maxChannel(255);
    pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

      buttonState = digitalRead(buttonPin);

 
      int brightnessUp;

      // let brightness of red light go up and down
      for(brightnessUp = 30; brightnessUp >=10; brightnessUp--){
        DmxSimple.write(10, 0);
        DmxSimple.write(1, 200);
        DmxSimple.write(6, 255);
        DmxSimple.write(7,brightnessUp);
        buttonState = digitalRead(buttonPin);
        
        // if button is pressed => let light use flickering white light
        if(buttonState == HIGH){
          delay(1000);
          DmxSimple.write(7, 0);
          DmxSimple.write(1, 200);
          DmxSimple.write(6, 230);
          DmxSimple.write(10, 255);
          delay(4000);
          
        }
        delay(100);
        buttonState = digitalRead(buttonPin);
        if(buttonState == HIGH){
          delay(1000);
          DmxSimple.write(7, 0);
          DmxSimple.write(1, 200);
          DmxSimple.write(6, 230);
          DmxSimple.write(10, 255);
          delay(4000);
          
        }
    
    }

    
    
    
      
    
    
    
   


}
