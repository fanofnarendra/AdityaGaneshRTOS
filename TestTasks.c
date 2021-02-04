
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t task1Handl = NULL;
TaskHandle_t task2Handl = NULL;

char* task1_name = "Task1";
char* task2_name = "Task2";

void myTask1(void *p)
{
	UBaseType_t priority;
	while(1)
	{
		priority = uxTaskPriorityGet(NULL);
		printf("Hello from:  %s\r priority: %ld \n\r",(char*)p, priority);
		fflush(stdout);
		//vTaskDelay(1000/portTICK_PERIOD_MS);
		vTaskPrioritySet(task1Handl, tskIDLE_PRIORITY);
		vTaskPrioritySet(task2Handl, tskIDLE_PRIORITY+1);
	}
}

void myTask2(void *p)
{
	UBaseType_t priority;
	while(1)
	{
		priority = uxTaskPriorityGet(NULL);
		printf("Hello from:  %s\r priority: %ld \n\r",(char*)p, priority);
		fflush(stdout);
		//vTaskDelay(2000/portTICK_PERIOD_MS);
		vTaskPrioritySet(task1Handl, tskIDLE_PRIORITY+1);
		vTaskPrioritySet(task2Handl, tskIDLE_PRIORITY);
	}
}

void main_TestTasks( void )
{
	xTaskCreate(myTask1, "T1", 200, (void *)task1_name, tskIDLE_PRIORITY, &task1Handl);
	xTaskCreate(myTask2, "T2", 200, (void *)task2_name, tskIDLE_PRIORITY+1, &task2Handl);

	vTaskStartScheduler();
	while(1);
}
