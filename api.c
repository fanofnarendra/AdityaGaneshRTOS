#include <api.h>
int getTemperature()
{
	srand(time(0));
	return (rand()%(100-20+1))+20;
}

int getPressure()
{
	srand(time(0));
	return (rand()%(10-1+1))+1;
}

int getHeight()
{
	srand(time(0));
	return (rand()%(1000-0+1))+0;
}
