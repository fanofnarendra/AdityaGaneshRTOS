
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include <linkedlist.h>

TaskHandle_t temperatureHandl = NULL;
TaskHandle_t pressureHandl = NULL;
TaskHandle_t heightHandl = NULL;
TaskHandle_t angleHandl = NULL;

TaskHandle_t edfHandl = NULL;

//TaskHandle_t* sortedTaskHandles[3];

//task which reads temperature periodically
void getTemperatureTask(void *p)
{
	int temperature;
	long tick;
	while(1)
	{
		tick = xTaskGetTickCount();
		temperature = getTemperature();
		printf("tick: %ld\t deadline: %ld\t temperature: %d \n", tick, deadlineTEMPERATURE, temperature);
		fflush(stdout);
		deadlineTEMPERATURE += periodTEMPERATURE;
		vTaskDelay(periodTEMPERATURE/portTICK_PERIOD_MS);
	}
}

//task which reads Pressure periodically
void getPressureTask(void *p)
{
	int pressure;
	long tick;
	while(1)
	{
		tick = xTaskGetTickCount();
		pressure = getPressure();
		printf("tick: %ld\t deadline: %ld\t pressure: %d \n", tick, deadlinePRESSURE, pressure);
		fflush(stdout);
		deadlinePRESSURE += periodPRESSURE;
		vTaskDelay(periodPRESSURE/portTICK_PERIOD_MS);
	}
}

//task which reads Height periodically
void getHeightTask(void *p)
{
	int height;
	long tick;
	while(1)
	{
		tick = xTaskGetTickCount();
		height = getHeight();
		printf("tick: %ld\t deadline: %ld\t height: %d \n", tick, deadlineHEIGHT, height);
		fflush(stdout);
		deadlineHEIGHT += periodHEIGHT;
		vTaskDelay(periodHEIGHT/portTICK_PERIOD_MS);
	}
}

//task which reads Angle periodically
void getAngleTask(void *p)
{
	int angle;
	long tick;
	while(1)
	{
		tick = xTaskGetTickCount();
		angle = getAngle();
		printf("tick: %ld\t deadline: %ld\t angle: %d \n", tick, deadlineHEIGHT, angle);
		fflush(stdout);
		deadlineANGLE += periodANGLE;
		vTaskDelay(periodANGLE/portTICK_PERIOD_MS);
	}
}

//sort task according to deadlines and store
/*
void sortTasks()
{
	if(deadlineTEMPERATURE == deadlinePRESSURE)
	{
		if(deadlineTEMPERATURE < deadlineHEIGHT)
		{
			sortedTaskHandles[0] = &temperatureHandl;
			sortedTaskHandles[1] = &pressureHandl;
			sortedTaskHandles[2] = &heightHandl;
		}
		else
		{
			sortedTaskHandles[0] = &heightHandl;
			sortedTaskHandles[1] = &temperatureHandl;
			sortedTaskHandles[2] = &pressureHandl;
		}
	}
	else if(deadlinePRESSURE == deadlineHEIGHT)
	{
		if(deadlinePRESSURE < deadlineTEMPERATURE)
		{
			sortedTaskHandles[0] = &pressureHandl;
			sortedTaskHandles[1] = &heightHandl;
			sortedTaskHandles[2] = &temperatureHandl;
		}
		else
		{
			sortedTaskHandles[0] = &temperatureHandl;
			sortedTaskHandles[1] = &pressureHandl;
			sortedTaskHandles[2] = &heightHandl;
		}
	}
	else if(deadlineTEMPERATURE == deadlineHEIGHT)
	{
		if(deadlineTEMPERATURE < deadlinePRESSURE)
		{
			sortedTaskHandles[0] = &temperatureHandl;
			sortedTaskHandles[1] = &heightHandl;
			sortedTaskHandles[2] = &pressureHandl;
		}
		else
		{
			sortedTaskHandles[0] = &pressureHandl;
			sortedTaskHandles[1] = &temperatureHandl;
			sortedTaskHandles[2] = &heightHandl;
		}
	}
	else if(deadlineTEMPERATURE < deadlinePRESSURE && deadlineTEMPERATURE < deadlineHEIGHT)
	{
		if(deadlinePRESSURE < deadlineHEIGHT)
		{
			sortedTaskHandles[0] = &temperatureHandl;
			sortedTaskHandles[1] = &pressureHandl;
			sortedTaskHandles[2] = &heightHandl;
		}
		else
		{
			sortedTaskHandles[0] = &temperatureHandl;
			sortedTaskHandles[1] = &heightHandl;
			sortedTaskHandles[2] = &pressureHandl;
		}
	}
	else if(deadlinePRESSURE < deadlineTEMPERATURE && deadlinePRESSURE < deadlineHEIGHT)
	{
		if(deadlineTEMPERATURE < deadlineHEIGHT)
		{
			sortedTaskHandles[0] = &pressureHandl;
			sortedTaskHandles[1] = &temperatureHandl;
			sortedTaskHandles[2] = &heightHandl;
		}
		else
		{
			sortedTaskHandles[0] = &pressureHandl;
			sortedTaskHandles[1] = &heightHandl;
			sortedTaskHandles[2] = &temperatureHandl;
		}
	}
	else if(deadlineHEIGHT < deadlineTEMPERATURE && deadlineHEIGHT < deadlinePRESSURE)
	{
		if(deadlineTEMPERATURE < deadlinePRESSURE)
		{
			sortedTaskHandles[0] = &heightHandl;
			sortedTaskHandles[1] = &temperatureHandl;
			sortedTaskHandles[2] = &pressureHandl;
		}
		else
		{
			sortedTaskHandles[0] = &heightHandl;
			sortedTaskHandles[1] = &pressureHandl;
			sortedTaskHandles[2] = &temperatureHandl;
		}
	}

}
*/

void printPriorityDeadlines()
{
	printf("Task:\t\tPriority\tDeadline\n");
	printf("Temperature:\t%lu\t\t%ld\n", uxTaskPriorityGet(temperatureHandl), deadlineTEMPERATURE);
	printf("Pressure:\t%lu\t\t%ld\n", uxTaskPriorityGet(pressureHandl), deadlinePRESSURE);
	printf("Height:\t\t%lu\t\t%ld\n", uxTaskPriorityGet(heightHandl), deadlineHEIGHT);
	//printf("Angle:\t\t%lu\t\t%ld\n\r", uxTaskPriorityGet(angleHandl), deadlineANGLE);
}

void vScheduleEDF(void *p)
{
	long tick;
	struct LinkedlistNode* head = (struct LinkedlistNode*)p;
	struct LinkedlistNode* ptr = NULL;
	int priority = 2;

	//period of this EDF task GCD of all task periods
	int periodEDF = gcdLinkedList(head);

	while(1)
	{
		tick = xTaskGetTickCount();
		printf("\n-----tick: %ld\t----EDF---------\n", tick);
		fflush(stdout);

        bubbleSortLinkedList(head);

        ptr = head;
        priority = 2;
        while(ptr != NULL)
        {
			vTaskPrioritySet(*(ptr->taskHandl), configMAX_PRIORITIES - priority++);
			ptr = ptr->next;
        }

		//print priorities and deadlines
		printPriorityDeadlines();

		vTaskDelay(periodEDF);
	}

}

void runTempPresHeight( void )
{
	xTaskCreate(getTemperatureTask, "getTemperatureTask", 200, (void *)0, tskIDLE_PRIORITY, &temperatureHandl);
	xTaskCreate(getPressureTask, "getPressureTask", 200, (void *)0, tskIDLE_PRIORITY, &pressureHandl);
	xTaskCreate(getHeightTask, "getHeightTask", 200, (void *)0, tskIDLE_PRIORITY, &heightHandl);
	//xTaskCreate(getAngleTask, "getAngleTask", 200, (void *)0, tskIDLE_PRIORITY, &angleHandl);

	//making linked list
	struct LinkedlistNode *head = NULL;
    insertAtTheBegin(&head, &heightHandl, &deadlineHEIGHT);
    insertAtTheBegin(&head, &pressureHandl, &deadlinePRESSURE);
    insertAtTheBegin(&head, &temperatureHandl, &deadlineTEMPERATURE);
    //insertAtTheBegin(&head, &angleHandl, &deadlineANGLE);

	//EDF Task: priority is highest
	xTaskCreate(vScheduleEDF, "edfTask", 1000, head, configMAX_PRIORITIES-1, &edfHandl);

	printf("Hi Ganesh");
	printf("Hi Aditya\n");

	vTaskStartScheduler();
	while(1);
}
