/*
  AppleRemoteIR.h - Send IR commands of AppleRemote.
  Copyright (c) NeoCat 2010. All right reserved.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
*/

#ifndef APPLE_REMOTE_IR_H
#define APPLE_REMOTE_IR_H

//#include <inttypes.h>
//#include <WProgram.h>

class AppleRemoteIR
{
   public:
	AppleRemoteIR(int irpin, byte id = 1);

	void send(byte key);
	
	void pairOn()	{ send(0x02); }
  void pairOff() { send(0x04); }  // aya add
	void menu()	{ send(0x03); }
	void play()	{ send(0x05); }
	void right()	{ send(0x06); }
	void left()	{ send(0x09); }
	void up()	{ send(0x0A); }
	void down()	{ send(0x0C); }
  void center() { send(0x5C); } // aya add
  
    private:
	int	pin;
	uint8_t	id;
	void	send38K(int time);
};

#endif
