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
   vTaskSuspend_Ignore();
}

void test_prvLEDTask_should_SetLEDOn(void)
{
	CallCount=0;
	vTaskSuspend_Ignore();
	LED_On_ExpectAndReturn(LEDParam, STATUS_SET);

	prvLEDTask((void *)&LEDParam);

	TEST_ASSERT_EQUAL_INT(STATUS_SET, ReturnStatus);

}

void test_prvLEDTask_should_ResumeLEDToggleTask(void)
{
	CallCount=1;
	vTaskSuspend_Ignore();
	vTaskResume_Ignore();

	prvLEDTask((void *)&LEDParam);

	TEST_ASSERT_EQUAL_INT(STATUS_TOGGLE, ReturnStatus);
}
