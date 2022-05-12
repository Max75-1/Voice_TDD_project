#include "VoiceTask.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm32l1xx_hal.h"
#include "stm32l1xx_hal_uart.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

#ifndef TEST
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
#else
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
#endif

void prvVoiceTask   ( void *pvParameters )
{
static char uartbuf[100];

	//HAL_UART_Transmit(&huart2,"I'm here !\r\n",13,400);

	vTaskSuspend(NULL);

	HAL_UART_Transmit(&huart2,"\r\nStart Record !!!\r\n",21,100);


  	memset(uartbuf,'\0',100*sizeof(char));
  	//HAL_UART_Transmit(&huart2,"AT\r\n",4,400);
  	HAL_UART_Transmit(&huart1,"AT\r\n",5,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC=1,1,1,600\r\n",20,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	vTaskSuspend(NULL);

  	HAL_UART_Transmit(&huart2,"\r\nStop Record !!!\r\n",21,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC=2\r\n",12,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);


  	vTaskSuspend(NULL);

  	HAL_UART_Transmit(&huart2,"\r\nStart Play !!!\r\n",19,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC=4,1,0,50,1\r\n",21,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	vTaskSuspend(NULL);

  	HAL_UART_Transmit(&huart2,"\r\nStop Play !!!\r\n",18,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC=5\r\n",12,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC=3,1\r\n",14,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,100);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,100);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,100);

  	vTaskSuspend(NULL);


  	while(1)
  	{

  	}
}

/*void prvVoiceTaskStopRecord   ( void *pvParameters )
{
static char uartbuf[100];

	vTaskSuspend(NULL);

	HAL_UART_Transmit(&huart2,"Stop Record !!!\r\n",18,400);

	memset(uartbuf,'\0',100*sizeof(char));
	HAL_UART_Transmit(&huart1,"AT+CREC=2\r\n",12,500);
	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);

	memset(uartbuf,'\0',100*sizeof(char));
	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,500);
	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);


	vTaskSuspend(NULL);

	while(1)
	{

	}

}*/

void prvVoiceTaskStartPlay   ( void *pvParameters )
{
static char uartbuf[100];

	vTaskSuspend(NULL);

	HAL_UART_Transmit(&huart2,"Start Play !!!\r\n",17,400);

  	//memset(uartbuf,'\0',100*sizeof(char));
  	//HAL_UART_Transmit(&huart2,"AT\r\n",4,400);
  	//HAL_UART_Transmit(&huart1,"AT\r\n",5,500);
  	//HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
  	//HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);

  	//memset(uartbuf,'\0',100*sizeof(char));
  	//HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,500);
  	//HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
  	//HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC=4,1,1,50,1\r\n",21,500);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);

  	memset(uartbuf,'\0',100*sizeof(char));
  	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,500);
  	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
  	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);

  	vTaskSuspend(NULL);

  	while(1)
  	{

  	}
}

void prvVoiceTaskStopPlay   ( void *pvParameters )
{
static char uartbuf[100];

	vTaskSuspend(NULL);

	HAL_UART_Transmit(&huart2,"Stop Play !!!\r\n",16,400);

	memset(uartbuf,'\0',100*sizeof(char));
	HAL_UART_Transmit(&huart1,"AT+CREC=5\r\n",12,500);
	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);

	memset(uartbuf,'\0',100*sizeof(char));
	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,500);
	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);

	memset(uartbuf,'\0',100*sizeof(char));
	HAL_UART_Transmit(&huart1,"AT+CREC=3,1\r\n",14,500);
	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);

	memset(uartbuf,'\0',100*sizeof(char));
	HAL_UART_Transmit(&huart1,"AT+CREC?\r\n",11,500);
	HAL_UART_Receive(&huart1,(uint8_t *)uartbuf,100,500);
	HAL_UART_Transmit(&huart2,(uint8_t *)uartbuf,100,500);



	vTaskSuspend(NULL);

	while(1)
	{

	}

}

