#include "unity.h"

#include "mock_stm32l1xx_hal_tim.h"
#include "stm32l1xx_it.h"
#include "Utils.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_TIM6_IRQHandler_should_ReturnStatusOkAfterTesting(void)
{
	HAL_TIM_IRQHandler_Ignore();

	TEST_ASSERT_EQUAL_INT(STATUS_OK,TIM6_IRQHandler());
}
