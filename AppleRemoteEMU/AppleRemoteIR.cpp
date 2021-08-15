/*
  AppleRemoteIR.cpp - Send IR commands of AppleRemote.
  Copyright (c) NeoCat 2010. All right reserved.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
*/
#include <Arduino.h>
#include "AppleRemoteIR.h"

AppleRemoteIR::AppleRemoteIR(int pin, byte id) : pin(pin), id(id)
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}

void AppleRemoteIR::send(uint8_t key)
{
	long data = ((long)id << 24) |
		    ((long)key << 16) |
		    (key == 0x02?0x87E0:0x87EE); /* special code for pairing */

	//send leader code
	send38K(9000);
	delayMicroseconds(4500);

	//send data
	for(int i = 0; i < 32; i++, data>>=1) {
		send38K(560);
		if((data & 1) == 0)
			delayMicroseconds(565);
		else
			delayMicroseconds(1690);
	}

	//stop bit
	send38K(560);
}

void AppleRemoteIR::send38K(int time)
{
	for(int i = 0; i < time/26; i++) {
		digitalWrite(pin, HIGH);
		delayMicroseconds(9);
		digitalWrite(pin, LOW);
		delayMicroseconds(8);
	}
}
