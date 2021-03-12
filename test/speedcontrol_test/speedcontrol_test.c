/**
 * @file speedcontrol_test.c.
 * @brief Tests for the speed control module.
 * @details This contains the tests divided into 3 groups. **TDD**, **state machine**, and **BVA** tests.
 */

#include "speedcontrol_test.h"

/**
 * @brief Sets the return values of the stubs.
 * @param name_of_switch Wanted return switch name.  
 * @param state_of_switch Wanted return switch state.
 * @param sw_duration Wanted return switch duration.
 * @details To disable stubs refer to speedcontrol_test.h.
 */
static void stubs_return(t_SWITCH name_of_switch, t_SWITCH_STATE state_of_switch, uint8_t sw_duration)
{
    #if STUBS_ENABLED
    SW_GetName_ExpectAndReturn(name_of_switch);
    SW_GetState_ExpectAndReturn(state_of_switch);
    SW_GetDuration_ExpectAndReturn(sw_duration);
    #endif
}


/**
 * \defgroup TESTING Testing Documentation
 * @{
 */
/**
 * \defgroup TDD TDD test cases.
 * @{
 */
/** @name TDD test cases.
 *  @details These are the tests cases derived from the requirements provided by swift act to drive the development.
 */
///@{ 
/**
 * @brief Construct TDD test group.
 */
TEST_GROUP(TDD);

/**
 * @brief TEST_SETUP is called before each test case to set the initial test environment by setting the motor speed to the initial speed **MID_SPEED.**
 *
 */
TEST_SETUP(TDD)
{
    MotorInit();
}

/**
 * @brief TEST_TEAR_DOWN is called after each test to reset the test environment to the previous state.
 *
 */
TEST_TEAR_DOWN(TDD)
{}

/**
 * @brief Default speed test case.
 */
TEST(TDD, DEFAULT_SPEED_MID)
{
    /*!
        * @par Given : Motor speed is unkown.
        * @par When  : motor_init() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief p switch test speed = MAX_SPEED test case.
 */
TEST(TDD, SW_PRESSURE_MAX)
{
    /*!
        * @par Given : p switch is pressed for 30 secs, and speed = MAX_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief p switch speed = MID_SPEED test case.
 */
TEST(TDD, SW_PRESSURE_MID)
{
    /*!
        * @par Given : p switch is pressed for 30 secs, and speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MIN_SPEED.
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

/**
 * @brief p switch speed = MIN_SPEED test case.
 */
TEST(TDD, SW_PRESSURE_MIN)
{
    /*!
        * @par Given : SW_PRESSURE is pressed for 30 secs, and speed = MIN_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed remains is MIN_SPEED.
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

/**
 * @brief -ve switch speed = MAX_SPEED test case.
 */
TEST(TDD, SW_MINUS_MAX)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, and speed = MAX_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief -ve switch speed = MID_SPEED test case.
 */
TEST(TDD, SW_MINUS_MID)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed,  and speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MIN_SPEED.
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

/**
 * @brief -ve switch speed = MIN_SPEED test case.
 */
TEST(TDD, SW_MINUS_MIN)
{
    /*!
        * @par Given : SW_MINUS is pre_pressed, speed = MIN_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MIN_SPEED.
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


/**
 * @brief +ve switch speed = MAX_SPEED test case.
 */
TEST(TDD, SW_PLUS_MAX)
{
    /*!
        * @par Given : SW_PLUS is pre_pressed, speed = MAX_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MAX_SPEED.
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

/**
 * @brief +ve switch speed = MID_SPEED test case.
 */
TEST(TDD, SW_PLUS_MID)
{
    /*!
        * @par Given : SW_PLUS is pre_pressed, speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MAX_SPEED.
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

/**
 * @brief +ve switch speed = MIN_SPEED test case.
 */
TEST(TDD, SW_PLUS_MIN)
{
    /*!
        * @par Given : SW_PLUS is pre_pressed, speed = MIN_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief Runs the TDD test group.
 */
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
///@}
/**@}*/



/**
 * \defgroup state_transition transition test cases.
 * @{
 */
/** @name State transition test cases.
 *  @details These are the tests cases for N-1 switch coverage.
 */
///@{ 
/**
 * @brief Construct state transition test group.
 */
TEST_GROUP(STATE_TRANSITION);

/**
 * @brief TEST_SETUP is called before each test case to set the initial test environment by setting the motor speed to the initial speed **MID_SPEED.**
 *
 */
TEST_SETUP(STATE_TRANSITION)
{
    MotorInit ();
}

/**
 * @brief TEST_TEAR_DOWN is called after each test to reset the test environment to the previous state.
 *
 */
TEST_TEAR_DOWN(STATE_TRANSITION)
{}

/**
 * @brief State transition MID -> MIN -> MID -> MIN.
 */
TEST(STATE_TRANSITION, STATE_MACHINE_1)
{
    /*!
        * @par Given : speed = MID_SPEED.
        * @par When  : state machine case 1 is tested.
        * @par Then  : follow sequence (MID, MIN, MID, MIN).
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

/**
 * @brief State transition MID -> MIN -> MID -> MAX.
 */
TEST(STATE_TRANSITION, STATE_MACHINE_2)
{
    /*!
        * @par Given : MID_SPEED.
        * @par When  : state machine case 2 is tested.
        * @par Then  : follow sequence (MID, MIN, MID, MAX).
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

/**
 * @brief State transition MID -> MAX -> MID -> MIN.
 */
TEST(STATE_TRANSITION, STATE_MACHINE_3)
{
    /*!
        * @par Given : MID_SPEED.
        * @par When  : state machine case 3 is tested.
        * @par Then  : follow sequence (MID, MAX, MID, MIN).
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

/**
 * @brief State transition MID -> MAX -> MID -> MAX.
 */
TEST(STATE_TRANSITION, STATE_MACHINE_4)
{
    /*!
        * @par Given : MID_SPEED.
        * @par When  : state machine case 4 is tested.
        * @par Then  : follow sequence (MID, MAX, MID, MAX).
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

/**
 * @brief Runs the state transition test group.
 */
TEST_GROUP_RUNNER(STATE_TRANSITION)
{
    RUN_TEST_CASE(STATE_TRANSITION, STATE_MACHINE_1);
    RUN_TEST_CASE(STATE_TRANSITION, STATE_MACHINE_2);
    RUN_TEST_CASE(STATE_TRANSITION, STATE_MACHINE_3);
    RUN_TEST_CASE(STATE_TRANSITION, STATE_MACHINE_4);
}
///@}
/**@}*/



/**
 * \defgroup EP_BVA EP and BVA test cases.
 * @{
 */
/** @name EP and BVA test cases.
 *  @details These are the tests cases for EP and BVA testing methods.
 */
///@{ 
/**
 * @brief Construct EP+BVA test group.
 */
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
 * @brief TEST_TEAR_DOWN is called after each test to reset the test environment to the previous state.
 *
 */
TEST_TEAR_DOWN(EP_BVA)
{}

/**
 * @brief Negative value read as a switch test case.
 */
TEST(EP_BVA, NEGATIVE_SWITCH_1)
{
    /*!
        * @par Given : Switch value is -1, switch state is pre_pressed, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief Negative value read as a switch state test case.
 */
TEST(EP_BVA, NEGATIVE_SWITCH_2)
{
    /*!
        * @par Given : +ve is pressed, switch state value is -1, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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


/**
 * @brief p switch sate released test case.
 */
TEST(EP_BVA, SW_PRESSURE_RELEASED)
{
    /*!
        * @par Given : p is released for 30 secs, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief p switch sate pre_pressed test case.
 */
TEST(EP_BVA, SW_PRESSURE_PRE_PRESSED)
{
    /*!
        * @par Given : p is pre_pressed for 30 secs (although physically impossible), motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief p switch pressed for 29 secs test case.
 */
TEST(EP_BVA, SW_PRESSURE_DURATION_1)
{
    /*!
        * @par Given : p is pressed for 29 secs, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief p switch pressed for 29 secs test case.
 */
TEST(EP_BVA, SW_PRESSURE_DURATION_2)
{
    /*!
        * @par Given : p is pressed for 30 secs, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MIN_SPEED.
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

/**
 * @brief p switch pressed for 31 secs test case.
 */
TEST(EP_BVA, SW_PRESSURE_DURATION_3)
{
    /*!
        * @par Given : p is pressed for 31 secs, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MIN_SPEED.
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

/**
 * @brief p switch pressed for 30 secs while speed is MIN_SPEED.
 */
TEST(EP_BVA, SW_PRESSURE_PRESSED_MIN)
{
    /*!
        * @par Given : p is pressed for 30 secs, motor speed = MIN_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MIN_SPEED.
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

/**
 * @brief p switch pressed for 30 secs while speed is MID_SPEED.
 */
TEST(EP_BVA, SW_PRESSURE_PRESSED_MID)
{
    /*!
        * @par Given : p is pressed for 30 secs, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MIN_SPEED.
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

/**
 * @brief p switch pressed for 30 secs while speed is MAX_SPEED.
 */
TEST(EP_BVA, SW_PRESSURE_PRESSED_MAX)
{
    /*!
        * @par Given : p is pressed for 30 secs, motor speed = MAX_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief p switch pre_released for 30 secs while speed is MID_SPEED.
 */
TEST(EP_BVA, SW_PRESSURE_PRE_RELEASE_MID)
{
    /*!
        * @par Given : p is pre_released for 30 secs (although impossible), motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
	*/

    /* Expected state and inputs*/
	uint8_t expected_motor_state = MID_SPEED;
    stubs_return(SW_PRESSURE, SW_S_PRE_RELEASED, 30);


    /* Arrange */
    MotorSet(MID_SPEED);

    /* Act */
    MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());

    /* Assert */
    TEST_ASSERT_EQUAL(expected_motor_state, MotorGet());
}

/**
 * @brief -ve switch released while speed is MID_SPEED.
 */
TEST(EP_BVA, SW_MINUS_RELEASED_MID)
{
    /*!
        * @par Given : -ve is released, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief -ve switch pre_pressed while speed is MIN_SPEED.
 */
TEST(EP_BVA, SW_MINUS_PRE_PRESSED_MIN)
{
    /*!
        * @par Given : -ve is pre_pressed, motor speed = MIN_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MIN_SPEED.
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

/**
 * @brief -ve switch pre_pressed while speed is MID_SPEED.
 */
TEST(EP_BVA, SW_MINUS_PRE_PRESSED_MID)
{
    /*!
        * @par Given : -ve is pre_pressed, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MIN_SPEED.
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

/**
 * @brief -ve switch pre_pressed while speed is MAX_SPEED.
 */
TEST(EP_BVA, SW_MINUS_PRE_PRESSED_MAX)
{
    /*!
        * @par Given : -ve is pre_pressed, motor speed = MAX_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief -ve switch pressed while speed is MID_SPEED.
 */
TEST(EP_BVA, SW_MINUS_PRESSED_MID)
{
    /*!
        * @par Given : -ve is pressed, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief -ve switch pre_released while speed is MID_SPEED.
 */
TEST(EP_BVA, SW_MINUS_PRE_RELEASED_MID)
{
    /*!
        * @par Given : -ve is pre_released, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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


/**
 * @brief +ve switch released while speed is MID_SPEED.
 */
TEST(EP_BVA, SW_PLUS_RELEASED)
{
    /*!
        * @par Given : +ve is released, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief +ve switch pre_pressed while speed is MIN_SPEED.
 */
TEST(EP_BVA, SW_PLUS_PRE_PRESSED_MIN)
{
    /*!
        * @par Given : +ve is pre_pressed, motor speed = MIN_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief +ve switch pre_pressed while speed is MIN_SPEED.
 */
TEST(EP_BVA, SW_PLUS_PRE_PRESSED_MID)
{
    /*!
        * @par Given : +ve is pre_pressed, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MAX_SPEED.
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

/**
 * @brief +ve switch pre_pressed while speed is MAX_SPEED.
 */
TEST(EP_BVA, SW_PLUS_PRE_PRESSED_MAX)
{
    /*!
        * @par Given : +ve is pre_pressed, motor speed = MAX_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MAX_SPEED.
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

/**
 * @brief +ve switch pressed while speed is MID_SPEED.
 */
TEST(EP_BVA, SW_PLUS_PRESSED)
{
    /*!
        * @par Given : +ve is pressed, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief +ve switch pre_released while speed is MID_SPEED.
 */
TEST(EP_BVA, SW_PLUS_PRE_RELEASED)
{
    /*!
        * @par Given : +ve is released, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief The switch value is higher than the limit.
 */
TEST(EP_BVA, HIGHER_VALUES_SWITCH)
{
    /*!
        * @par Given : Higher switch value (3) is passed to the function, motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief The switch value is higher than the limit.
 */
TEST(EP_BVA, HIGHER_VALUES_SWITCH_STATE)
{
    /*!
        * @par Given : +ve switch with higher state of (4), motor speed = MID_SPEED.
        * @par When  : motor_update() is called.
        * @par Then  : Motor speed is MID_SPEED.
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

/**
 * @brief Runs EP + BVA test group.
 */
TEST_GROUP_RUNNER(EP_BVA)
{
    RUN_TEST_CASE(EP_BVA, NEGATIVE_SWITCH_1);
    RUN_TEST_CASE(EP_BVA, NEGATIVE_SWITCH_2);

    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_RELEASED);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_PRE_PRESSED);

    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_DURATION_1);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_DURATION_2);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_DURATION_3);

    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_PRESSED_MIN);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_PRESSED_MID);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_PRESSED_MAX);
    RUN_TEST_CASE(EP_BVA, SW_PRESSURE_PRE_RELEASE_MID);

    RUN_TEST_CASE(EP_BVA, SW_MINUS_RELEASED_MID);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_PRE_PRESSED_MIN);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_PRE_PRESSED_MID);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_PRE_PRESSED_MAX);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_PRESSED_MID);
    RUN_TEST_CASE(EP_BVA, SW_MINUS_PRE_RELEASED_MID);

    RUN_TEST_CASE(EP_BVA, SW_PLUS_RELEASED);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_PRE_PRESSED_MIN);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_PRE_PRESSED_MID);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_PRE_PRESSED_MAX);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_PRESSED);
    RUN_TEST_CASE(EP_BVA, SW_PLUS_PRE_RELEASED);

    RUN_TEST_CASE(EP_BVA, HIGHER_VALUES_SWITCH);
    RUN_TEST_CASE(EP_BVA, HIGHER_VALUES_SWITCH_STATE);
}
///@}
/**@}*/
/**@}*/