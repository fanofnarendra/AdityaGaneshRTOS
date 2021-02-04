
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include <api.h>

TaskHandle_t temperatureHandl = NULL;
TaskHandle_t pressureHandl = NULL;
TaskHandle_t heightHandl = NULL;

void getTemperatureTask(void *p)
{
	int temperature;
	long tick;
	while(1)
	{
		tick = xTaskGetTickCount();
		temperature = getTemperature();
		printf("tick: %ld\t temperature: %d \n\r", tick, temperature);
		fflush(stdout);
		vTaskDelay(periodTEMPERATURE/portTICK_PERIOD_MS);
	}
}

void getPressureTask(void *p)
{
	int pressure;
	long tick;
	while(1)
	{
		tick = xTaskGetTickCount();
		pressure = getPressure();
		printf("tick: %ld\t pressure: %d \n\r", tick, pressure);
		fflush(stdout);
		vTaskDelay(periodPRESSURE/portTICK_PERIOD_MS);
	}
}

void getHeightTask(void *p)
{
	int height;
	long tick;
	while(1)
	{
		tick = xTaskGetTickCount();
		printf("tick: %ld\t height: %d \n\r", tick, height);
		height = getHeight();
		fflush(stdout);
		vTaskDelay(periodHEIGHT/portTICK_PERIOD_MS);
	}
}


void runTempPresHeight( void )
{
	xTaskCreate(getTemperatureTask, "getTemperatureTask", 200, (void *)0, tskIDLE_PRIORITY, &temperatureHandl);
	xTaskCreate(getPressureTask, "getPressureTask", 200, (void *)0, tskIDLE_PRIORITY, &pressureHandl);
	xTaskCreate(getHeightTask, "getHeightTask", 200, (void *)0, tskIDLE_PRIORITY, &heightHandl);
	printf("Hi Ganesh");
	printf("Hi Aditya");
	vTaskStartScheduler();
	while(1);
}
