#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "main.h"
#include "stm32l1xx_hal_gpio.h"
#include "stm32l1xx_hal.h"
#include "Utils.h"

#define LED_1 GPIO_PIN_2
#define LED_2 GPIO_PIN_3

STATUS_T LED_Init(void);
STATUS_T LED_On(uint16_t led);
STATUS_T LED_Off(uint16_t led);
STATUS_T LED_ToggleTwoLEDs(void);
STATUS_T LED_GetStatus(uint16_t led);
void Power_On(void);

#endif // LED_H
