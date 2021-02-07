#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define periodTEMPERATURE 500	//period in milliseconds
#define periodPRESSURE 1000		//period in milliseconds
#define periodHEIGHT 1500		//period in milliseconds

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
