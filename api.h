#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define periodTEMPERATURE 400	//period in milliseconds
#define periodPRESSURE 600		//period in milliseconds
#define periodHEIGHT 800		//period in milliseconds

static long int deadlineTEMPERATURE = periodTEMPERATURE;		//Deadline of getTemperature()
static long int deadlinePRESSURE = periodPRESSURE;				//Deadline of getPressure()
static long int deadlineHEIGHT = periodHEIGHT;					//Deadline of getHeight()

int getTemperature();

int getPressure();

int getHeight();

int lcm(int, int);

int gcd(int, int);

int gcdThree(int, int, int);

int getMinimum(int, int, int);
