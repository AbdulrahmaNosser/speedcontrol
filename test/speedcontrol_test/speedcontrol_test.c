#include <stdint.h>
#include <stdbool.h>

#include "../unity/unity_fixture.h"
#include "../mocks/Mockswitch.h"

#include "../../source/speedcontrol/speedcontrol.h"
#include "../../source/switch/switch.h"

//enable/disable stubs
#define STUBS_ENABLED true

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

TEST(TDD, SW_PRESSURE_MAX)
{
    /*!
        * @par Given : SW_PRESSURE is pressed for 30 secs, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;

    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(SW_PRESSURE);
    sw_get_state_ExpectAndReturn(SW_S_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);
    #endif

    /* Arrange */
    motor_set(MAX_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}

TEST(TDD, SW_PRESSURE_MID)
{
    /*!
        * @par Given : SW_PRESSURE is pressed for 30 secs, MID_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MID to MIN
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;

    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(SW_PRESSURE);
    sw_get_state_ExpectAndReturn(SW_S_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);
    #endif

    /* Arrange */
    motor_set(MID_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}

TEST(TDD, SW_PRESSURE_MIN)
{
    /*!
        * @par Given : SW_PRESSURE is pressed for 30 secs, MIN_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed remains MIN
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;

    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(SW_PRESSURE);
    sw_get_state_ExpectAndReturn(SW_S_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);
    #endif

    /* Arrange */
    motor_set(MIN_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}


//SW_MINUS tests
TEST(TDD, SW_MINUS_MAX)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;

    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(SW_MINUS);
    sw_get_state_ExpectAndReturn(SW_S_PRE_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);
    #endif

    /* Arrange */
    motor_set(MAX_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}

TEST(TDD, SW_MINUS_MID)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MID_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MID to MIN
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;

    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(SW_MINUS);
    sw_get_state_ExpectAndReturn(SW_S_PRE_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);
    #endif

    /* Arrange */
    motor_set(MID_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}

TEST(TDD, SW_MINUS_MIN)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MIN_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed remains MIN
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;

    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(SW_MINUS);
    sw_get_state_ExpectAndReturn(SW_S_PRE_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);
    #endif

    /* Arrange */
    motor_set(MIN_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}



//SW_PLUS tests
TEST(TDD, SW_PLUS_MAX)
{
    /*!
        * @par Given : SW_PLUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed remains MAX
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MAX_SPEED;

    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(SW_PLUS);
    sw_get_state_ExpectAndReturn(SW_S_PRE_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);
    #endif

    /* Arrange */
    motor_set(MAX_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}

TEST(TDD, SW_PLUS_MID)
{
    /*!
        * @par Given : SW_PLUS is pre_pressed, MID_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MID to MAX
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MAX_SPEED;

    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(SW_PLUS);
    sw_get_state_ExpectAndReturn(SW_S_PRE_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);
    #endif

    /* Arrange */
    motor_set(MID_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}

TEST(TDD, SW_PLUS_MIN)
{
    /*!
        * @par Given : SW_PLUS is pre_pressed, MIN_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MIN to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;

    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(SW_PLUS);
    sw_get_state_ExpectAndReturn(SW_S_PRE_PRESSED);
    sw_get_pressed_duration_ExpectAndReturn(30);
    #endif

    /* Arrange */
    motor_set(MIN_SPEED);

    /* Act */
    motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
}

TEST_GROUP_RUNNER(TDD)
{
    RUN_TEST_CASE(TDD, DEFAULT_SPEED_MID);

    RUN_TEST_CASE(TDD, SW_PRESSURE_MAX);
    RUN_TEST_CASE(TDD, SW_PRESSURE_MID);
    RUN_TEST_CASE(TDD, SW_PRESSURE_MIN);

    RUN_TEST_CASE(TDD, SW_MINUS_MAX);
    RUN_TEST_CASE(TDD, SW_MINUS_MID);
    RUN_TEST_CASE(TDD, SW_MINUS_MIN);

    RUN_TEST_CASE(TDD, SW_PLUS_MAX);
    RUN_TEST_CASE(TDD, SW_PLUS_MID);
    RUN_TEST_CASE(TDD, SW_PLUS_MIN);
}
