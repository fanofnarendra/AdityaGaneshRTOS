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
/*
int getAngle()
{
	srand(time(0));
	return (rand()%(359-0+1))+0;
}
*/
long int gcdTwo(long int a, long int b)
{
  if (b == 0)
    return a;
  return gcdTwo(b, a % b);
}

