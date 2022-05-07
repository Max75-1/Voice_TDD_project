#include "LEDTask.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm32l1xx_hal.h"
#include "stm32l1xx_hal_uart.h"
#include "main.h"

//extern UART_HandleTypeDef huart1;
//extern UART_HandleTypeDef huart2;

#ifndef TEST
static int CallCount=0;
extern TaskHandle_t xHandle_LEDToggle;
extern UART_HandleTypeDef huart2;
#else
int CallCount;
TaskHandle_t xHandle_LEDToggle=NULL;
#endif

extern uint16_t LEDParam;
STATUS_T ReturnStatus=STATUS_OK;

void prvLEDTask   ( void *pvParameters )
{
	vTaskSuspend(NULL);

	LEDParam=*((uint16_t *)pvParameters);

	while(1){
		CallCount++;
		switch(CallCount){
			case 1: ReturnStatus=LED_On(LEDParam); break;
			case 2: vTaskResume(xHandle_LEDToggle);
					ReturnStatus=STATUS_TOGGLE;
			break;
			case 3: vTaskSuspend(xHandle_LEDToggle);
					ReturnStatus=LED_Off(LEDParam);
					CallCount=0;
					if(LEDParam==LED_1)
						LEDParam=LED_2;
					else
						LEDParam=LED_1;
			break;
		}
		vTaskSuspend(NULL);
#ifdef TEST
		break;
#endif
	}

/*#ifndef TEST
		HAL_UART_Transmit(&huart2, "I'm here !!!\r\n", 15, 100 );
#endif*/
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
