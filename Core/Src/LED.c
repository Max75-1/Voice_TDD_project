#include "LED.h"

STATUS_T LED_On(uint16_t led)
{
	HAL_GPIO_WritePin(GPIOC,led,GPIO_PIN_SET);

	return STATUS_OK;
}

STATUS_T LED_Off(uint16_t led)
{
	HAL_GPIO_WritePin(GPIOC,led,GPIO_PIN_RESET);

	return STATUS_OK;
}

STATUS_T LED_Init(void)
{
	LED_Off(LED_1);
	LED_Off(LED_2);
}
