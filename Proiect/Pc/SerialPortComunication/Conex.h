#ifndef __CONEX__
#define __CONEX__

#include "Serial.h"

#define SLEEP_TIME 2000
class Conex
{
	Serial* SP;
	bool SendInfoRequest();
public:
	bool Connect(int port);

	int ReadInfo(char* buffer, int dataLength, int *queueSize);

	bool WriteInfo(char* writeChar, int size);

};
#endif 