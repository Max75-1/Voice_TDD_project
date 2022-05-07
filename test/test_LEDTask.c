#include "unity.h"

#include "mock_FreeRTOS.h"
#include "mock_task.h"
#include "mock_main.h"
#include "LEDTask.h"
#include "mock_LED.h"
#include "mock_stm32l1xx_hal.h"

extern int CallCount;
extern STATUS_T ReturnStatus;
uint16_t LEDParam=LED_1;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_prvLEDTask_should_SuspendItselfInStart(void)
{
	CallCount=-1;
	vTaskSuspend_ExpectAnyArgs();
	vTaskSuspend_ExpectAnyArgs();

	prvLEDTask(&LEDParam);

	TEST_ASSERT_EQUAL_INT(STATUS_OK,ReturnStatus);
}

void test_prvLEDTask_should_SetLEDOn(void)
{
	CallCount=0;
	vTaskSuspend_Ignore();
	LED_On_ExpectAnyArgsAndReturn(STATUS_SET);

	prvLEDTask(&LEDParam);

	TEST_ASSERT_EQUAL_INT(STATUS_SET, ReturnStatus);
}

void test_prvLEDTask_should_ResumeLEDToggleTask(void)
{
	CallCount=1;
	vTaskSuspend_Ignore();
	vTaskResume_ExpectAnyArgs();

	prvLEDTask((void *)&LEDParam);

	TEST_ASSERT_EQUAL_INT(STATUS_TOGGLE, ReturnStatus);
}

void test_prvLEDTask_should_SetLEDOff_and_SuspendToggleTask(void)
{
	CallCount=2;
	vTaskSuspend_Ignore();
	LED_Off_ExpectAnyArgsAndReturn(STATUS_RESET);

	prvLEDTask(&LEDParam);

	TEST_ASSERT_EQUAL_INT(STATUS_RESET, ReturnStatus);
	TEST_ASSERT_EQUAL_INT(0, CallCount);
	//TEST_ASSERT_EQUAL_INT(LED_2, LEDParam);
}
