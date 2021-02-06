#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define periodTEMPERATURE 400
#define periodPRESSURE 600
#define periodHEIGHT 800

static long int deadlineTEMPERATURE = periodTEMPERATURE;
static long int deadlinePRESSURE = periodPRESSURE;
static long int deadlineHEIGHT = periodHEIGHT;

int getTemperature();

int getPressure();

int getHeight();

int lcm(int, int);

int gcd(int, int);

int gcdThree(int, int, int);

int getMinimum(int, int, int);

//
//int calcHyperperiod(int[]);
//
//int calcFrameSize();
