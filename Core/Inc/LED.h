#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "main.h"
#include "Utils.h"

#define LED_1 GPIO_PIN_2

void LED_Init(void);
STATUS_T LED_On(uint16_t led);
STATUS_T LED_Off(uint16_t led);

#endif // LED_H
