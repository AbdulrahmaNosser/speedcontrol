#include "../unity/unity_fixture.h"

TEST_GROUP(speed_control);

TEST_SETUP(speed_control)
{}

TEST_TEAR_DOWN(speed_control)
{}

TEST(speed_control, DEFAULT_SPEED)
{
    TEST_FAIL_MESSAGE("Start here");
}

TEST_GROUP_RUNNER(speed_control)
{
    RUN_TEST_CASE(speed_control, DEFAULT_SPEED);
}
