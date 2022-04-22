#include "unity.h"
#include "mock_main.h"
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
	TEST_ASSERT_EQUAL_INT(STATUS_ERROR, LED_On(LED_1));
}
