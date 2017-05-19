#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H

#include "Arduino.h"
#include <EEPROM.h>

/*
protocol V2: http://support.robotis.com/en/product/actuator/dynamixel_pro/communication/instruction_status_packet.htm
		 ______________________________________________________
		|					NetworkController				   |
		|______________________________________________________|
		|	-state : unsigned char							   |
		|	-instruction : unsigned char					   |
		|	-messageData[] : unsigned char					   |
		|	-messageIndex : unsigned char					   |
		|	-returnPacket[] : unsigned char 				   |
		|	-id : unsigned char								   |
		|	-messageLength : unsigned int					   |
		|	-crc : unsigned int								   |
		|	-crc_compute : unsigned int						   |
		|													   |
		|	//define:										   |
		|		- Instructions								   |
		|		- Packet Constant Value						   |
		|		- Register Address							   |
		|______________________________________________________|
		|	+networkController()							   |
		|	-resetMachineState() : void						   |
		|	-returnStatus() : void							   |
		|	-machineState(unsigned char) : void				   |
		|	-compute_crc(...) : unsigned short		   cf--->  |  cf:  http://support.robotis.com/en/product/actuator/dynamixel_pro/communication/crc.htm
		|______________________________________________________|



*/

class NetworkController
{
  public:
  unsigned char ID;
  unsigned char tabRegister[100];
  
    //  default
 //   NetworkController();
    //
	
	unsigned char tab_lenght = 0;
	
  //  init & update
  //  void initialize();
   void machineState(unsigned char data);
   void returnStatus();
    //


   protected:
    //  protected attributes
    unsigned char state=0;
	unsigned char instruction=0x00;
	unsigned char messageData[50];
	unsigned char messageIndex=0x00;
	unsigned int crc=0;
	unsigned int crc_compute=0;
	unsigned int messageLength=0;
	unsigned char returnPacket[50];
	unsigned char tabParameter[50];
	unsigned char index_tabParameter=0;
	unsigned int numberParameter=0;
	unsigned int addressParameter=0;
	unsigned char *pointer;
	
	//

	//

    //  network managment
    void resetMachineState();

    //

	// crc calcul
	unsigned short compute_crc(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size);
	//


	// Constant value for Basic Structure Packet
	#define HEADER_1 0xFF
	#define HEADER_2 0xFF
	#define HEADER_3 0xFD
	#define RESERVED 0x00

	#define BROADCAST_ID 0xFE
    
	
	//
	
	#define MODEL_NUMBER 0x0406
	#define FIRMWARE 0x26
	
	#define BAUDRATE 115200
	//

	
	
	
	
    //  instructions
	#define INST_PING 0x01
	#define INST_READ 0x02
	#define INST_WRITE 0x03
	#define INST_REG_WRITE 0x04
	#define INST_ACTION 0x05
	#define INST_FACTORY_RESET 0x06
	#define INST_REBOOT 0x08
	#define INST_STATUS_RETURN 0x55
	#define INST_SYNC_READ 0x82
	#define INST_SYNC_WRITE 0x83
	#define INST_BULK_READ 0x92
	#define INST_BULK_WRITE 0x93
    //

};



#endif