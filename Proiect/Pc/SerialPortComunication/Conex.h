#ifndef __CONEX__
#define __CONEX__

#include "Serial.h"
#define LENGTH 200
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

	char* ReadInfo()
	{
		char incomingData[LENGTH] = "";			// don't forget to pre-allocate memory
		int dataLength = LENGTH - 1;
		int readResult = 0;

		if (SP->IsConnected())
		{
			//Request
			char msg[] = "ready";
			SP->WriteData(msg, strlen(msg));
			readResult = SP->ReadData(incomingData, dataLength);
			FILE* f;
			errno_t er = fopen_s(&f, "Input", "w");
			if (strlen(incomingData))
			{
				if (f != NULL)
					fprintf(f, "%s\n", incomingData);
				else
					printf("%d", er);
				system("cls");
				printf(incomingData);
			}
			fclose(f);
			Sleep(SLEEP_TIME);
		}
		return "";
	}
};
#endif 