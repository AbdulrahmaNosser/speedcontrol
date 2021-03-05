#include <stdint.h>

#include "../unity/unity_fixture.h"

#include "../../source/speedcontrol/speedcontrol.h"
#include "../../source/switch/switch.h"

static uint8_t pre_state_of_motor = 0;

TEST_GROUP(valid_speed_control);

TEST_SETUP(valid_speed_control)
{
    motor_init();
}

TEST_TEAR_DOWN(valid_speed_control)
{}

////////////
TEST(valid_speed_control, DEFAULT_SPEED_MID)
{
    TEST_ASSERT_EQUAL(MID_SPEED, motor_speed_get());
}



TEST(valid_speed_control, VE_POS_PREPRESSED_MID_if_MIN)
{
    motor_set(MIN_SPEED);
    motor_cmd (VE_POS_PREPRESSED);
    TEST_ASSERT_EQUAL(MID_SPEED, motor_speed_get());
}

TEST(valid_speed_control, VE_POS_PREPRESSED_MAX_if_MID)
{
    motor_cmd (VE_POS_PREPRESSED);
    TEST_ASSERT_EQUAL(MAX_SPEED, motor_speed_get());
}

TEST(valid_speed_control, VE_POS_PREPRESSED_MAX_if_MAX)
{
    motor_set(MAX_SPEED);
    motor_cmd (VE_POS_PREPRESSED);
    TEST_ASSERT_EQUAL(MAX_SPEED, motor_speed_get());
}

//////////////
TEST(valid_speed_control, VE_NEG_PREPRESSED_MIN_if_MIN)
{
    motor_set(MIN_SPEED);
    motor_cmd (VE_NEG_PREPRESSED);
    TEST_ASSERT_EQUAL(MIN_SPEED, motor_speed_get());
}

TEST(valid_speed_control, VE_NEG_PREPRESSED_MIN_if_MID)
{
    motor_cmd (VE_NEG_PREPRESSED);
    TEST_ASSERT_EQUAL(MIN_SPEED, motor_speed_get());
}

TEST(valid_speed_control, VE_NEG_PREPRESSED_MID_if_MAX)
{
    motor_set(MAX_SPEED);
    motor_cmd (VE_NEG_PREPRESSED);
    TEST_ASSERT_EQUAL(MID_SPEED, motor_speed_get());
}

//////////////
TEST(valid_speed_control, P_SWCH_PRESSED_MIN_if_MIN)
{
    motor_set(MIN_SPEED);
    motor_cmd (VE_NEG_PREPRESSED);
    TEST_ASSERT_EQUAL(MIN_SPEED, motor_speed_get());
}

TEST(valid_speed_control, P_SWCH_PRESSED_MIN_if_MID)
{
    motor_cmd (VE_NEG_PREPRESSED);
    TEST_ASSERT_EQUAL(MIN_SPEED, motor_speed_get());
}

TEST(valid_speed_control, P_SWCH_PRESSED_MID_if_MAX)
{
    motor_set(MAX_SPEED);
    motor_cmd (VE_NEG_PREPRESSED);
    TEST_ASSERT_EQUAL(MID_SPEED, motor_speed_get());
}

///////////

TEST_GROUP_RUNNER(valid_speed_control)
{
    RUN_TEST_CASE(valid_speed_control, DEFAULT_SPEED_MID);

    RUN_TEST_CASE(valid_speed_control, VE_POS_PREPRESSED_MID_if_MIN);
    RUN_TEST_CASE(valid_speed_control, VE_POS_PREPRESSED_MAX_if_MID);
    RUN_TEST_CASE(valid_speed_control, VE_POS_PREPRESSED_MAX_if_MAX);

    RUN_TEST_CASE(valid_speed_control, VE_NEG_PREPRESSED_MIN_if_MIN);
    RUN_TEST_CASE(valid_speed_control, VE_NEG_PREPRESSED_MIN_if_MID);
    RUN_TEST_CASE(valid_speed_control, VE_NEG_PREPRESSED_MID_if_MAX);

    RUN_TEST_CASE(valid_speed_control, P_SWCH_PRESSED_MIN_if_MIN);
    RUN_TEST_CASE(valid_speed_control, P_SWCH_PRESSED_MIN_if_MID);
    RUN_TEST_CASE(valid_speed_control, P_SWCH_PRESSED_MID_if_MAX);
}

TEST_GROUP(invalid_speed_control);

TEST_SETUP(invalid_speed_control)
{
    motor_init();
    pre_state_of_motor = motor_speed_get();
}

TEST_TEAR_DOWN(invalid_speed_control)
{}

TEST(invalid_speed_control, NEGATIVE_VALUES)
{
    motor_cmd (-1);
    TEST_ASSERT_EQUAL(pre_state_of_motor, motor_speed_get());
}

TEST(invalid_speed_control, PARTITION_5)
{
    motor_cmd (VE_POS_PRESSED);
    TEST_ASSERT_EQUAL(pre_state_of_motor, motor_speed_get());

    motor_cmd (VE_POS_RELEASED);
    TEST_ASSERT_EQUAL(pre_state_of_motor, motor_speed_get());
}

TEST(invalid_speed_control, PARTITION_9)
{
    motor_cmd (VE_NEG_PRESSED);
    TEST_ASSERT_EQUAL(pre_state_of_motor, motor_speed_get());

    motor_cmd (P_SWCH_PREPRESSED);
    TEST_ASSERT_EQUAL(pre_state_of_motor, motor_speed_get());
}

TEST(invalid_speed_control, PARTITION_13)
{
    motor_cmd (P_SWCH_PRERELEASED);
    TEST_ASSERT_EQUAL(pre_state_of_motor, motor_speed_get());

    motor_cmd (P_SWCH_RELEASED + 1);
    TEST_ASSERT_EQUAL(pre_state_of_motor, motor_speed_get());
}

TEST_GROUP_RUNNER(invalid_speed_control)
{
    RUN_TEST_CASE(invalid_speed_control, NEGATIVE_VALUES);
    RUN_TEST_CASE(invalid_speed_control, PARTITION_5);
    RUN_TEST_CASE(invalid_speed_control, PARTITION_9);
    RUN_TEST_CASE(invalid_speed_control, PARTITION_13);
}