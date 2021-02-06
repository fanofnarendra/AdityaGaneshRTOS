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

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int gcdThree(int a, int b, int c)
{
  if (b == 0)
    return a;
  int d = gcd(b, a % b);
  return gcd(c, d % c);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int getMinimum(int x, int y, int z)
{
	return (x<y)? ((x<z)?x:z):((y<z)?y:z);
}

