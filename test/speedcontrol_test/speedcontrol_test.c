#include <stdint.h>

#include "../unity/unity_fixture.h"
#include "../mocks/Mockswitch.h"

#include "../../source/speedcontrol/speedcontrol.h"
#include "../../source/switch/switch.h"

static uint8_t pre_state_of_motor = 0;

TEST_GROUP(TDD);

TEST_SETUP(TDD)
{
    motor_init ();
}

TEST_TEAR_DOWN(TDD)
{}

TEST(TDD, DEFAULT_SPEED_MID)
{
    /*!
        * @par Given : Motor speed is unkown
        * @par When  : motor_init() is called
        * @par Then  : Motor speed is miduim
	*/

    /* Expected state */
	uint8_t expected_motor_state = MID_SPEED;

    /* Arrange */
    motor_set(MIN_SPEED);

    /* Act */
    motor_init();

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}

TEST(TDD, P_SWITCH)
{
    /*!
        * @par Given : P is pressed for 30 secs
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    sw_get_name_ExpectAndReturn(SW_PRESSURE);
    sw_get_state_ExpectAndReturn(SW_S_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);

    /* Arrange */
    motor_set(MAX_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}

TEST_GROUP_RUNNER(TDD)
{
    RUN_TEST_CASE(TDD, DEFAULT_SPEED_MID);
    RUN_TEST_CASE(TDD, P_SWITCH);
}