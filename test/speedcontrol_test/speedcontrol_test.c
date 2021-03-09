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
    SW_GetName_ExpectAndReturn(name_of_switch);
    SW_GetState_ExpectAndReturn(state_of_switch);
    SW_GetDuration_ExpectAndReturn(sw_duration);
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
    MotorInit();
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
    MotorSet(MIN_SPEED);

    /* Act */
    MotorInit();

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorSet(MAX_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorSet(MIN_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorSet(MAX_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorSet(MIN_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorSet(MAX_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorSet(MIN_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
    MotorInit ();
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
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
    }

    //MIN_SPEED to MID_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MID_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
    }

    //MID_SPEED to MIN_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MIN_SPEED;
        stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


        /* Arrange */

        /* Act */
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
    }

    //MIN_SPEED to MID_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MID_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
    }

    //MID_SPEED to MAX_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MAX_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
    }

    //MAX_SPEED to MID_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MID_SPEED;
        stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
    }

    //MID_SPEED to MIN_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MIN_SPEED;
        stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


        /* Arrange */

        /* Act */
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
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
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
    }

    //MAX_SPEED to MID_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MID_SPEED;
        stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
    }

    //MID_SPEED to MAX_SPEED
    {
        /* Expected state and inputs*/
        uint8_t expected_motor_state = MAX_SPEED;
        stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


        /* Arrange */

        /* Act */
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

        /* Assert */
        TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
    }
}

TEST_GROUP_RUNNER(STATE_MACHINE)
{
    RUN_TEST_CASE(STATE_MACHINE, STATE_MACHINE_1);
    RUN_TEST_CASE(STATE_MACHINE, STATE_MACHINE_2);
    RUN_TEST_CASE(STATE_MACHINE, STATE_MACHINE_3);
    RUN_TEST_CASE(STATE_MACHINE, STATE_MACHINE_4);
}


TEST_GROUP(EP_BVA);

/**
 * @brief TEST_SETUP is called before each test case to set the initial the test environment by setting the motor speed to the initial speed MID_SPEED
 *
 */
TEST_SETUP(EP_BVA)
{
    MotorInit();
}

/**
 * @brief TEST_TEAR_DOWN is called after each test to reset the test environment to the previous state
 *
 */
TEST_TEAR_DOWN(EP_BVA)
{}



TEST(EP_BVA, NEGATIVE_SWITCH_1)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(-1, SW_S_PRE_PRESSED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, NEGATIVE_SWITCH_2)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PLUS, -1, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}



TEST(EP_BVA, SW_PRESSURE_DURATION_1)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PRESSURE, SW_S_RELEASED, 30);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PRESSURE_DURATION_2)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PRESSURE, SW_S_PRE_PRESSED, 30);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PRESSURE_DURATION_3)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PRESSURE, SW_S_PRESSED, 29);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PRESSURE_STATE_1)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;
    stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PRESSURE_STATE_2)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;
    stubs_return(SW_PRESSURE, SW_S_PRESSED, 31);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PRESSURE_STATE_3)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;
    stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


    /* Arrange */
    MotorSet(MIN_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PRESSURE_STATE_4)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;
    stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PRESSURE_STATE_5)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PRESSURE, SW_S_PRESSED, 30);


    /* Arrange */
    MotorSet(MAX_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}


TEST(EP_BVA, SW_MINUS_1)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_MINUS, SW_S_RELEASED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_MINUS_2)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;
    stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


    /* Arrange */
    MotorSet(MIN_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_MINUS_3)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MIN_SPEED;
    stubs_return(SW_MINUS, SW_S_PRE_PRESSED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_MINUS_4)
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
    MotorSet(MAX_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_MINUS_5)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_MINUS, SW_S_PRESSED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_MINUS_6)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, MAX_SPEED
        * @par When  : motor_update() is called
        * @par Then  : Motor speed MAX to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_MINUS, SW_S_PRE_RELEASED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}


TEST(EP_BVA, SW_PLUS_1)
{
    /*!
        * @par Given : SW_PLUS is SW_S_RELEASED, MID_SPEED
        * @par When  : MotorUpdate() is called
        * @par Then  : Motor speed remains MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PLUS, SW_S_RELEASED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PLUS_2)
{
    /*!
        * @par Given : SW_PLUS is SW_S_PRE_PRESSED, MIN_SPEED
        * @par When  : MotorUpdate() is called
        * @par Then  : Motor speed MIN to MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


    /* Arrange */
    MotorSet(MIN_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PLUS_3)
{
    /*!
        * @par Given : SW_PLUS is SW_S_PRE_PRESSED, MID_SPEED
        * @par When  : MotorUpdate() is called
        * @par Then  : Motor speed MID to MAX
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MAX_SPEED;
    stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PLUS_4)
{
    /*!
        * @par Given : SW_PLUS is SW_S_PRE_PRESSED, MAX_SPEED
        * @par When  : MotorUpdate() is called
        * @par Then  : Motor speed remains MAX
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MAX_SPEED;
    stubs_return(SW_PLUS, SW_S_PRE_PRESSED, 0);


    /* Arrange */
    MotorSet(MAX_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PLUS_5)
{
    /*!
        * @par Given : SW_PLUS is SW_S_PRESSED, MID_SPEED
        * @par When  : MotorUpdate() is called
        * @par Then  : Motor speed remains MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PLUS, SW_S_PRESSED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, SW_PLUS_6)
{
    /*!
        * @par Given : SW_PLUS is SW_S_PRE_RELEASED, MID_SPEED
        * @par When  : MotorUpdate() is called
        * @par Then  : Motor speed remains MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PLUS, SW_S_PRE_RELEASED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, HIGHER_VALUES_1)
{
    /*!
        * @par Given : SW_PLUS + 1 is SW_S_PRE_RELEASED, MID_SPEED
        * @par When  : MotorUpdate() is called
        * @par Then  : Motor speed remains MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PLUS + 1, SW_S_PRE_RELEASED, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

TEST(EP_BVA, HIGHER_VALUES_2)
{
    /*!
        * @par Given : SW_PLUS is SW_S_PRE_RELEASED + 1, MID_SPEED
        * @par When  : MotorUpdate() is called
        * @par Then  : Motor speed remains MID
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PLUS, SW_S_PRE_RELEASED + 1, 0);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}


TEST_GROUP_RUNNER(EP_BVA)
{
    RUN_TEST_CASE(EP_BVA, NEGATIVE_SWITCH_1);
    RUN_TEST_CASE(EP_BVA, NEGATIVE_SWITCH_2);

    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_DURATION_1);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_DURATION_2);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_DURATION_3);

    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_STATE_1);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_STATE_2);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_STATE_3);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_STATE_4);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_STATE_5);

    RUN_TEST_CASE(EP_BVA, SW_MINUS_1);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_2);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_3);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_4);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_5);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_6);

    RUN_TEST_CASE(EP_BVA, SW_PLUS_1);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_2);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_3);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_4);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_5);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_6);

    RUN_TEST_CASE(EP_BVA, HIGHER_VALUES_1);
    RUN_TEST_CASE(EP_BVA, HIGHER_VALUES_2);
}