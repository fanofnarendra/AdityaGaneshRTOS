#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define periodTEMPERATURE 300
#define periodPRESSURE 400
#define periodHEIGHT 500

static long int deadlineTEMPERATURE = periodTEMPERATURE;
static long int deadlinePRESSURE = periodPRESSURE;
static long int deadlineHEIGHT = periodHEIGHT;

int getTemperature();

int getPressure();

int getHeight();
//
//int gcd(int, int);
//
//int lcm(int, int);
//
//int calcHyperperiod(int[]);
//
//int calcFrameSize();

int getMinimum(int, int, int);
