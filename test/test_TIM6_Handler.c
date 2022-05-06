#include "unity.h"

#include "mock_stm32l1xx_hal_tim.h"
#include "mock_stm32l1xx_hal_gpio.h"
#include "mock_LED.h"
#include "stm32l1xx_it.h"
#include "Utils.h"

extern GPIO_PinState PrevButtonState, ButtonState;
extern int SetStateCount;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_TIM6_IRQHandler_should_GetButtonState(void)
{
	HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_SET);
	HAL_TIM_IRQHandler_Ignore();
	TIM6_IRQHandler();

	TEST_ASSERT_EQUAL_INT(GPIO_PIN_SET,ButtonState);
}

void test_TIM6_IRQHandler_should_IncreaseSetStateCount_if_ButtonIsSet(void)
{
	SetStateCount=0;
	HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_SET);
	HAL_TIM_IRQHandler_Ignore();
	TIM6_IRQHandler();

	TEST_ASSERT_EQUAL_INT(1,SetStateCount);
}

void test_TIM6_IRQHandler_should_SetTheSetStateCountToZero_if_ButtonIsReset(void)
{
	SetStateCount=1;
	HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_RESET);
	HAL_TIM_IRQHandler_Ignore();
	TIM6_IRQHandler();

	TEST_ASSERT_EQUAL_INT(0,SetStateCount);
}

void test_TIM6_IRQHandler_should_SetTheSetStateCountToZero_and_SetPrevButtonStateToSet_if_SetStateCountBiggerThan50(void)
{
	SetStateCount=52;
	HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_SET);
	LED_ToggleTwoLEDs_IgnoreAndReturn(STATUS_OK);
	HAL_TIM_IRQHandler_Ignore();
	TIM6_IRQHandler();

	TEST_ASSERT_EQUAL_INT(GPIO_PIN_SET,PrevButtonState);
	TEST_ASSERT_EQUAL_INT(0,SetStateCount);
}

void test_TIM6_IRQHandler_should_ToggleLEDs_if_SetStateCountBiggerThan50(void)
{
	SetStateCount=52;
	HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_SET);
	LED_ToggleTwoLEDs_IgnoreAndReturn(STATUS_OK);
	HAL_TIM_IRQHandler_Ignore();
	TIM6_IRQHandler();

	TEST_ASSERT_EQUAL_INT(GPIO_PIN_SET,PrevButtonState);
	TEST_ASSERT_EQUAL_INT(0,SetStateCount);
}

/*void test_TIM6_IRQHandler_should_ReturnStatusOkAfterTesting(void)
{
	Timer1=1;
	HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_RESET);

	HAL_TIM_IRQHandler_Ignore();

	TEST_ASSERT_EQUAL_INT(STATUS_OK,TIM6_IRQHandler());
}

void test_TIM6_IRQHandler_should_GetPrevButtonStateInStart(void)
{
	Timer1=0;
	HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_RESET);

	TEST_ASSERT_EQUAL_INT(GPIO_PIN_RESET,PrevButtonState);

	HAL_TIM_IRQHandler_Ignore();

	TEST_ASSERT_EQUAL_INT(STATUS_OK,TIM6_IRQHandler());
}*/

/*void test_TIM6_IRQHandler_should_CheckStabilityStateOfButton(void)
{
	 Timer1=0;
	 HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_SET);
	 HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_SET);
	 HAL_TIM_IRQHandler_Ignore();        // If you want to make sure that this gets called

	 // Call the function
	 TEST_ASSERT_EQUAL_INT(STATUS_OK,TIM6_IRQHandler());

	 // Check that things have been updated as you expect
	 TEST_ASSERT_EQUAL_INT(1, Timer1);   // Did you mean to check that Timer was updated to 1?
	 TEST_ASSERT_EQUAL_INT(GPIO_PIN_SET,PrevButtonState);


	 // Setup conditions for next call of the function
	 Timer1=100;
	 HAL_GPIO_ReadPin_IgnoreAndReturn(GPIO_PIN_SET);
	 HAL_TIM_IRQHandler_Ignore();        // If you want to make sure that this gets called

	 // Call the function
	 TEST_ASSERT_EQUAL_INT(STATUS_OK,TIM6_IRQHandler());

	 // Check the expected variable states
	 TEST_ASSERT_EQUAL_INT(GPIO_PIN_SET,ButtonState);
	 TEST_ASSERT_EQUAL_INT(PrevButtonState,ButtonState);
	 TEST_ASSERT_EQUAL_INT(0,Timer1);  // Why are you checking this value? did you mean to check that it was updated to 101?
	 TEST_ASSERT_EQUAL_INT(1,StabilyFlag);
}*/
