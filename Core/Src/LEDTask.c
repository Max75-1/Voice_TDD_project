#include "LEDTask.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm32l1xx_hal.h"
#include "main.h"

//extern UART_HandleTypeDef huart1;
//extern UART_HandleTypeDef huart2;

#ifndef TEST
static int CallCount=0;
extern TaskHandle_t xHandle_LEDToggle;
#else
int CallCount=0;
TaskHandle_t xHandle_LEDToggle=NULL;
#endif

extern uint16_t LEDParam;
STATUS_T ReturnStatus;

void prvLEDTask   ( void *pvParameters )
{
	LEDParam=*((uint16_t *)pvParameters);

	vTaskSuspend(NULL);

	CallCount++;
	switch(CallCount){
		case 1: ReturnStatus=LED_On(LEDParam); break;
		case 2: vTaskResume(xHandle_LEDToggle);
				ReturnStatus=STATUS_TOGGLE;
		break;
	}
}

void prvLEDToggleTask( void *pvParameters )
{
uint16_t led=*((uint16_t *)pvParameters);

	vTaskSuspend(NULL);

	while(1){
		LED_On(led);
		HAL_Delay(100);
		LED_Off(led);
		HAL_Delay(100);
	}

}
