#include <stdio.h>
#include <tchar.h>
#include <string>
#include <time.h>
#include "Conex.h"
#define LENGTH 500
#define READ_COMMAND "R"
#define WRITE_COMMAND "W"
#define INPUT_FILENAME "Input"
#define OUTPUT_FILENAME "Output"

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
	
	//while (true)
	for (int i = 0; i < 1000; ++i)
	{
		Sleep(2000);
		FILE *fInput, *fOutput;
		errno_t erInput = fopen_s(&fInput, INPUT_FILENAME, "w");
		errno_t erOutput = fopen_s(&fOutput, OUTPUT_FILENAME, "a+");
		if (erInput || erOutput)
		{
			printf("\nFailed to open files!(%d %d)", erInput, erOutput);
			exit(1);
		}

		char incomingData[LENGTH];
		int dataLength = LENGTH - 1;
		incomingData[LENGTH-1] = 0;
		
		int queueSize;
		c.WriteInfo(READ_COMMAND, sizeof(READ_COMMAND - 1));
		Sleep(1000);
		int readBytes = c.ReadInfo(incomingData, dataLength, &queueSize);
		if (readBytes)
		{
			fwrite(incomingData, sizeof(char), readBytes, fInput);
			system("cls");
			//Replace(incomingData, readBytes);
			printf(incomingData);
			printf("\nQueueSize:%d", queueSize);
			if (queueSize > 164)
			{
				printf("Time since program start:%d", GetTimeDif());
				Sleep(INFINITE);
			}
		}

		fseek(fOutput, 0, SEEK_END);   // non-portable
		int size = ftell(fOutput);
		char* outgoingData = new char[size];
		rewind(fOutput);
		if (size)
		{
			fread(outgoingData, sizeof(char), size, fOutput);
			c.WriteInfo(WRITE_COMMAND, strlen(WRITE_COMMAND - 1));
			Sleep(1000);
			c.WriteInfo(outgoingData, size);
			printf("Writing to Arduino");
		}
		_fcloseall();
		delete outgoingData;
	}
	return 0;
}