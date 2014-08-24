#ifndef __CONEX__
#define __CONEX__

#include "Serial.h"

#define SLEEP_TIME 2000
class Conex
{
	Serial* SP;
	bool SendInfoRequest();
public:
	bool Connect()
	{
		SP = new Serial("\\\\.\\COM4");    // adjust as needed
		if (SP->IsConnected())
		{
			printf("We're connected\n");
			return true;
		}
		return false;
	}

	int ReadInfo(char* buffer, int dataLength, int *queueSize)
	{
		int readResult = 0;
		if (SP->IsConnected())
		{
			//Request
			readResult = SP->ReadData(buffer, dataLength, queueSize);
		}
		return readResult;
	}
	bool WriteInfo(char* writeChar, int size)
	{
		printf(writeChar);
		if (SP->IsConnected())
		{
			char msg[] = "Write";
			bool result = SP->WriteData(msg, strlen(msg));
			result = SP->WriteData(writeChar, size);
			if (result)
				return true;
		}
		return false;
	}
};
#endif 