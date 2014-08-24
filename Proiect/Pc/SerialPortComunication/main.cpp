#include <stdio.h>
#include <tchar.h>
#include <string>
#include "Conex.h"


// application reads from the specified serial port and reports the collected data
int _tmain(int argc, _TCHAR* argv[])
{
	printf("Welcome to the serial test app!\n\n");
	Conex c;
	c.Connect();
	while(true)
		c.ReadInfo();
	return 0;
}