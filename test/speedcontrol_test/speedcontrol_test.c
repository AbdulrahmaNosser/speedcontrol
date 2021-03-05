#include <stdint.h>

#include "../unity/unity_fixture.h"

#include "../../source/speedcontrol/speedcontrol.h"
#include "../../source/switch/switch.h"

static uint8_t pre_state_of_motor = 0;

TEST_GROUP(speed_control);

TEST_SETUP(speed_control)
{
    motor_init ();
}

TEST_TEAR_DOWN(speed_control)
{}

////////////
TEST(speed_control, DEFAULT_SPEED_MID)
{
    TEST_ASSERT_EQUAL(MID_SPEED, motor_speed_get());
}


//partetion_1
TEST(speed_control, NEGATIVE_VALUES)
{
    generate_cmd (PB_PRESSURE , -1);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );

    generate_cmd (-1 , PB_PRE_PRESSED);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );
}

//partetion_2
TEST(speed_control, PB_PRESSURE_1)
{
    motor_set (MIN_SPEED);
    generate_cmd (PB_PRESSURE , PB_PRESSED);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );
}

//partetion_3
TEST(speed_control, PB_PRESSURE_2)
{
    motor_set (MID_SPEED);
    generate_cmd (PB_PRESSURE , PB_PRESSED);
    TEST_ASSERT_EQUAL( SPEED_MINUS, cmd_get() );
}
TEST(speed_control, PB_PRESSURE_3)
{
    motor_set (MAX_SPEED);
    generate_cmd (PB_PRESSURE , PB_PRESSED);
    TEST_ASSERT_EQUAL( SPEED_MINUS, cmd_get() );
}

//partetion_4
TEST(speed_control, PB_PRESSURE_4)
{
    motor_set (MIN_SPEED);
    generate_cmd (PB_PRESSURE , PB_PRE_RELEASED);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );
}
TEST(speed_control, PB_MINUS_1)
{
    motor_set (MIN_SPEED);
    generate_cmd (PB_MINUS , PB_PRE_PRESSED);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );
}

//partetion_5
TEST(speed_control, PB_MINUS_2)
{
    motor_set (MID_SPEED);
    generate_cmd (PB_MINUS , PB_PRE_PRESSED);
    TEST_ASSERT_EQUAL( SPEED_MINUS, cmd_get() );
}
TEST(speed_control, PB_MINUS_3)
{
    motor_set (MAX_SPEED);
    generate_cmd (PB_MINUS , PB_PRE_PRESSED);
    TEST_ASSERT_EQUAL( SPEED_MINUS, cmd_get() );
}

//partetion_6
TEST(speed_control, PB_MINUS_4)
{
    motor_set (MIN_SPEED);
    generate_cmd (PB_MINUS , PB_PRESSED);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );
}
TEST(speed_control, PB_PLUS_1)
{
    motor_set (MAX_SPEED);
    generate_cmd (PB_MINUS , PB_RELEASED);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );
}

//partetion_7
TEST(speed_control, PB_PLUS_2)
{
    motor_set (MIN_SPEED);
    generate_cmd (PB_PLUS , PB_PRE_PRESSED);
    TEST_ASSERT_EQUAL( SPEED_PLUS, cmd_get() );
}
TEST(speed_control, PB_PLUS_3)
{
    motor_set (MID_SPEED);
    generate_cmd (PB_PLUS , PB_PRE_PRESSED);
    TEST_ASSERT_EQUAL( SPEED_PLUS, cmd_get() );
}

//partetion_8
TEST(speed_control, PB_PLUS_4)
{
    motor_set (MAX_SPEED);
    generate_cmd (PB_PLUS , PB_PRE_PRESSED);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );
}
TEST(speed_control, PB_PLUS_5)
{
    motor_set (MAX_SPEED);
    generate_cmd (PB_PLUS , PB_PRE_RELEASED);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );
}
TEST(speed_control, HIGHER_VALUES)
{
    generate_cmd (PB_PLUS + 1 , PB_PRE_PRESSED);
    TEST_ASSERT_EQUAL( STATUS_QOU, cmd_get() );
}


TEST_GROUP_RUNNER(speed_control)
{
    RUN_TEST_CASE(speed_control, DEFAULT_SPEED_MID);
    RUN_TEST_CASE(speed_control, NEGATIVE_VALUES);
    RUN_TEST_CASE(speed_control, PB_PRESSURE_1);
    RUN_TEST_CASE(speed_control, PB_PRESSURE_2);
    RUN_TEST_CASE(speed_control, PB_PRESSURE_3);
    RUN_TEST_CASE(speed_control, PB_PRESSURE_4);
    RUN_TEST_CASE(speed_control, PB_MINUS_1);
    RUN_TEST_CASE(speed_control, PB_MINUS_2);
    RUN_TEST_CASE(speed_control, PB_MINUS_3);
    RUN_TEST_CASE(speed_control, PB_MINUS_4);
    RUN_TEST_CASE(speed_control, PB_PLUS_1);
    RUN_TEST_CASE(speed_control, PB_PLUS_2);
    RUN_TEST_CASE(speed_control, PB_PLUS_3);
    RUN_TEST_CASE(speed_control, PB_PLUS_4);
    RUN_TEST_CASE(speed_control, PB_PLUS_5);
    RUN_TEST_CASE(speed_control, HIGHER_VALUES);
}
