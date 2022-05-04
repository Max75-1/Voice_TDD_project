#include "LED.h"

STATUS_T LED_On(uint16_t led)
{
	HAL_GPIO_WritePin(GPIOC,led,GPIO_PIN_SET);

	return STATUS_SET;
}

STATUS_T LED_Off(uint16_t led)
{
	HAL_GPIO_WritePin(GPIOC,led,GPIO_PIN_RESET);

	return STATUS_RESET;
}

STATUS_T LED_Init(void)
{
	LED_Off(LED_1);
	LED_Off(LED_2);

	return STATUS_OK;
}

STATUS_T LEDs_Toggle(){
	if(HAL_GPIO_ReadPin(GPIOC,LED_1)==GPIO_PIN_SET){
		LED_Off(LED_1);
		LED_On(LED_2);
	}else{
		LED_Off(LED_2);
		LED_On(LED_1);
	}

	return STATUS_OK;
}
