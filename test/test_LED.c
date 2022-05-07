#include "unity.h"
#include "mock_main.h"
#include "mock_stm32l1xx_hal_gpio.h"
#include "mock_stm32l1xx_hal.h"
#include "LED.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*void test_LED_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement LED");
}*/

void test_LED_On_should_SetLedOn(void)
{
	HAL_GPIO_WritePin_Expect(GPIOC,LED_1,GPIO_PIN_SET);
	TEST_ASSERT_EQUAL_INT(STATUS_SET, LED_On(LED_1));
}

void test_LED_Off_should_SetLedOff(void)
{
	HAL_GPIO_WritePin_Expect(GPIOC,LED_1,GPIO_PIN_RESET);
	TEST_ASSERT_EQUAL_INT(STATUS_RESET, LED_Off(LED_1));
}

void test_LED_Init_should_SetAllLedsOff(void)
{
	HAL_GPIO_WritePin_Expect(GPIOC,LED_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin_Expect(GPIOC,LED_2,GPIO_PIN_RESET);
	TEST_ASSERT_EQUAL_INT(STATUS_OK, LED_Init());
}

