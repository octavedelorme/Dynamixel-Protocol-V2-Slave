#include "networkcontroller.h"


NetworkController network_controller = NetworkController();


void setup() {
  // put your setup code here, to run once:

Serial1.begin(BAUDRATE);
Serial.begin(1000000);
Serial.println("                              ******************  START  ******************");
Serial.println("--------------------------------------------------------------------------------------------------------");
Serial.println(" ");

pinMode (2, OUTPUT);
digitalWrite(2, HIGH);
//digitalWrite(13, HIGH);

// Model Number (2 bytes) (Value Default 350 (DEC) so -> Model_Byte_Low : 0x5E  and Model_Byte_High : 0x01 
  network_controller.tabRegister[0]=0x5E;
  network_controller.tabRegister[1]=0x1;
// Version of Firmware
  network_controller.tabRegister[2]=0x26;
// ID
  network_controller.tabRegister[3]=0x05;
  //network_controller.ID=0x05;
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial1.available())
  {
   int c = Serial1.read(); 
if(c >= 0)network_controller.machineState(c);   
//if fin du message
//
//network_controller.returnStatus();
  }

}


