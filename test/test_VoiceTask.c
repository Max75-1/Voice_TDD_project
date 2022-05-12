#include "unity.h"
#include "mock_FreeRTOS.h"
#include "mock_task.h"
#include "mock_main.h"
#include "mock_LED.h"
#include "mock_stm32l1xx_hal.h"
#include "mock_stm32l1xx_hal_uart.h"
#include "VoiceTask.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_VoiceTask_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement VoiceTask");
}
