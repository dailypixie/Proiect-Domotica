#include <stdio.h>
#include <tchar.h>
#include <string>
#include <time.h>
#include "Conex.h"
#define LENGTH 500
#define READ_COMMAND "R"
#define WRITE_COMMAND "W"
#define INPUT_FILENAME "Input"
#define SANITY_CHECK 80

time_t gTime;
void InitTime()
{
	time(&gTime);
}
int GetTimeDif()
{
	time_t curTime;
	time(&curTime);
	return difftime(curTime, gTime);
}
int _tmain(int argc, _TCHAR* argv[])
{
	InitTime();
	Conex c;
	c.Connect();
	
	while (true)
	{
		char incomingData[LENGTH];
		int dataLength = LENGTH - 1;
		incomingData[LENGTH-1] = 0;
		
		int queueSize;
	REQUEST:
		c.WriteInfo(READ_COMMAND, sizeof(READ_COMMAND - 1));
		Sleep(500);
	READBYTES:
		int readBytes = c.ReadInfo(incomingData, dataLength, &queueSize);
		if (readBytes)
		{
			if (readBytes > SANITY_CHECK)
			{
				FILE *fInput;
				errno_t erInput = fopen_s(&fInput, INPUT_FILENAME, "w");
				if (erInput)
				{
					printf("\nFailed to open file!Error: %d!", erInput);
					exit(1);
				}
				fwrite(incomingData, sizeof(char), readBytes, fInput);
				system("cls");
				printf(incomingData);
				printf("\n QueueSize:%d", queueSize);
			}
			else
			{
				goto REQUEST;
			}
		}
		else
		{
			Sleep(1000);
			goto READBYTES;
		}
		_fcloseall();
	}
	return 0;
}