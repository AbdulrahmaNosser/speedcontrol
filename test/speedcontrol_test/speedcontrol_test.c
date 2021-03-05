#include <stdint.h>

#include "../unity/unity_fixture.h"

#include "../../source/speedcontrol/speedcontrol.h"

TEST_GROUP(speed_control);

TEST_SETUP(speed_control)
{}

TEST_TEAR_DOWN(speed_control)
{}

TEST(speed_control, DEFAULT_SPEED_MEDIUM)
{
    motor_init();
    TEST_ASSERT_EQUAL(MAX_SPEED, motor_speed_get());
}

TEST_GROUP_RUNNER(speed_control)
{
    RUN_TEST_CASE(speed_control, DEFAULT_SPEED_MEDIUM);
}
