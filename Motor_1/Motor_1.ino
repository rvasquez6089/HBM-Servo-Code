
/* MOTOR 1
  -------------------------------------------------------------
  Mechaduino 0.1 Firmware  v0.1.3
  SAM21D18 (Arduino Zero compatible), AS5047 encoder, A4954 driver

  All Mechaduino related materials are released under the
  Creative Commons Attribution Share-Alike 4.0 License
  https://creativecommons.org/licenses/by-sa/4.0/

  Many thanks to Will Church, Marco Farrugia, Kai Wolter, Trampas Stern, Mike Anton.
  --------------------------------------------------------------
  
  Controlled via a SerialUSB terminal at 115200 baud.

  Implemented serial commands are:

 s  -  step
 d  -  dir
 p  -  print [step number] , [encoder reading]

 c  -  calibration routine
 e  -  check encoder diagnositics
 q  -  parameter query

 x  -  position mode
 v  -  velocity mode
 x  -  torque mode

 y  -  enable control loop
 n  -  disable control loop
 r  -  enter new setpoint

 j  -  step response
 k  -  edit controller gains -- note, these edits are stored in volatile memory and will be reset if power is cycled
 g  -  generate sine commutation table
 m  -  print main menu


  ...see serialCheck() in Utils for more details

*/

#include "Utils.h"
#include "Parameters.h"
#include "State.h"
#include "analogFastWrite.h"

//////////////////////////////////////
/////////////////SETUP////////////////
//////////////////////////////////////


void setup()        // This code runs once at startup
{                         
   
  digitalWrite(ledPin,HIGH);        // turn LED on 
  setupPins();                      // configure pins
  setupTCInterrupts();              // configure controller interrupt
  SerialUSB.begin(115200);
  Serial1.begin(115200);          
  delay(3000);                      // This delay seems to make it easier to establish a connection when the Mechaduino is configured to start in closed loop mode.  
  serialMenu();                     // Prints menu to serial monitor
  setupSPI();                       // Sets up SPI for communicating with encoder
  digitalWrite(ledPin,LOW);         // turn LED off 
  

  // Uncomment the below lines as needed for your application.
  // Leave commented for initial calibration and tuning.
  
  //    configureStepDir();           // Configures setpoint to be controlled by step/dir interface
  //    configureEnablePin();         // Active low, for use wath RAMPS 1.4 or similar
                   // start in position mode
    //yw = 0;
    Setstartangle(); //used to orient the start up location to 0 degrees. 
     enableTCInterrupts();         // uncomment this line to start in closed loop 
     mode = 'x'; 
    
}
  


//////////////////////////////////////
/////////////////LOOP/////////////////
//////////////////////////////////////


void loop()                 // main loop
{

      //serialCheck();

        while (Serial1.available() == 0)  {}
        r = Serial1.parseFloat();
        SerialUSB.println(r);

 


  
  
}





