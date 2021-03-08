/**
 * @file speedcontrol_test.c
 * @author Abdulrahman Nosser (abdulrahman.nosser@gmail.com)
 * @brief Tests for the speed control module
 * @details This contains the tests divided into 3 groups. TDD, state machine, and BVA tests
 */

#include <stdint.h>
#include <stdbool.h>

#include "../unity/unity_fixture.h"
#include "../mocks/Mockswitch.h"

#include "../../source/speedcontrol/speedcontrol.h"
#include "../../source/switch/switch.h"

/**
 * @brief change the value of STUBS_ENABLED to false to turn off stubs and to use real functions
 *
 */
#define STUBS_ENABLED true

static void stubs_return(t_SWITCH name_of_switch, t_SWITCH_STATE state_of_switch, uint8_t sw_duration)
{
    #if STUBS_ENABLED
    sw_get_name_ExpectAndReturn(name_of_switch);
    sw_get_state_ExpectAndReturn(state_of_switch);
    sw_get_pressed_duration_ExpectAndReturn(sw_duration);
    #endif
}

/**
 * @brief Construct TDD test group
 *
 */
TEST_GROUP(TDD);

/**
 * @brief TEST_SETUP is called before each test case to set the initial the test environment by setting the motor speed to the initial speed MID_SPEED
 *
 */
TEST_SETUP(TDD)
{
    motor_init();
}

/**
 * @brief TEST_TEAR_DOWN is called after each test to reset the test environment to the previous state
 *
 */
TEST_TEAR_DOWN(TDD)
{}

/**
 * @brief Defauls speed test case
 *
 */
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
    stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


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
    stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


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
    stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


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
    stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


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
    stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


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
    stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


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
    stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


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
    stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);

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
    stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


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



TEST_GROUP(STATE_MACHINE);

TEST_SETUP(STATE_MACHINE)
{
    motor_init ();
}

TEST_TEAR_DOWN(STATE_MACHINE)
{}

//MID_SPEED to MIN_SPEED to MID_SPEED to MIN_SPEED
TEST(STATE_MACHINE, STATE_MACHINE_1)
{
    /*!
        * @par Given : MID_SPEED
        * @par When  : state machine case 1 is tested
        * @par Then  : follow sequence (MID, MIN, MID, MIN)
	*/

    //MID_SPEED to MIN_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MIN_SPEED;
        stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }

    //MIN_SPEED to MID_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MID_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }

    //MID_SPEED to MIN_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MIN_SPEED;
        stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }
}

//MID_SPEED to MIN_SPEED to MID_SPEED to MAX_SPEED
TEST(STATE_MACHINE, STATE_MACHINE_2)
{
    /*!
        * @par Given : MID_SPEED
        * @par When  : state machine case 2 is tested
        * @par Then  : follow sequence (MID, MIN, MID, MAX)
	*/

    //MID_SPEED to MIN_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MIN_SPEED;
        stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }

    //MIN_SPEED to MID_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MID_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }

    //MID_SPEED to MAX_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MAX_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }
}

//MID_SPEED to MAX_SPEED to MID_SPEED to MIN_SPEED
TEST(STATE_MACHINE, STATE_MACHINE_3)
{
    /*!
        * @par Given : MID_SPEED
        * @par When  : state machine case 3 is tested
        * @par Then  : follow sequence (MID, MAX, MID, MIN)
	*/

    //MID_SPEED to MAX_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MAX_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }

    //MAX_SPEED to MID_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MID_SPEED;
        stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }

    //MID_SPEED to MIN_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MIN_SPEED;
        stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }
}

//MID_SPEED to MAX_SPEED to MID_SPEED to MAX_SPEED
TEST(STATE_MACHINE, STATE_MACHINE_4)
{
    /*!
        * @par Given : MID_SPEED
        * @par When  : state machine case 1 is tested
        * @par Then  : follow sequence (MID, MAX, MID, MAX)
	*/

    //MID_SPEED to MAX_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MAX_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }

    //MAX_SPEED to MID_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MID_SPEED;
        stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }

    //MID_SPEED to MAX_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MAX_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        motor_update(sw_get_name(), sw_get_state(), sw_get_pressed_duration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, motor_get());
    }
}

TEST_GROUP_RUNNER(STATE_MACHINE)
{
    RUN_TEST_CASE(STATE_MACHINE, STATE_MACHINE_1);
    RUN_TEST_CASE(STATE_MACHINE, STATE_MACHINE_2);
    RUN_TEST_CASE(STATE_MACHINE, STATE_MACHINE_3);
    RUN_TEST_CASE(STATE_MACHINE, STATE_MACHINE_4);
}
