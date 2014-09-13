#include "Conex.h"

bool Conex::Connect(int port)
{
	
	char temp[20];
	sprintf_s(temp, "%s%d", "\\\\.\\COM", port);
		SP = new Serial(temp);    // adjust as needed
	if (SP->IsConnected())
	{
		printf("We're connected\n");
		return true;
	}
	return false;
}
int Conex::ReadInfo(char* buffer, int dataLength, int *queueSize)
{
	int readResult = 0;
	if (SP->IsConnected())
	{
		//Request
		readResult = SP->ReadData(buffer, dataLength, queueSize);
	}
	return readResult;
}

bool Conex::WriteInfo(char* writeChar, int size)
{
	printf(writeChar);
	if (SP->IsConnected())
	{
		bool result = SP->WriteData(writeChar, size);
		if (result)
			return true;
	}
	return false;
}