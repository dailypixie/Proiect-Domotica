#include <stdio.h>
#include <tchar.h>
#include <string>
#include <time.h>
#include "Conex.h"
#define LENGTH 500
#define READ_COMMAND "R"
#define WRITE_COMMAND "W"
#define INPUT_FILENAME "Input"
#define SANITY_CHECK 14

int _tmain(int argc, _TCHAR* argv[])
{
	Conex c;
	printf("Introduce-ti portul dorit:");
	int port = 19;
	scanf_s("%d", &port);
	c.Connect(port);
	
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
				printf("\n QueueSize:%d", queueSize);
				printf("\n Size:%d", readBytes);
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