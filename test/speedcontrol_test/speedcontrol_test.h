#ifndef SPEEDCONTROL_TEST_H
#define SPEEDCONTROL_TEST_H

#include <stdbool.h>

#include "../../source/speedcontrol/speedcontrol.h"
#include "../../source/switch/switch.h"

#include "../unity/unity_fixture.h"
#include "../mocks/Mockswitch.h"

/**
 * @brief change the value of STUBS_ENABLED to false to turn off stubs and to use real functions
 *
 */
#define STUBS_ENABLED true

#define MAKE_UNITY_VERBOSE	argc = 2; argv[1] = "-v"

static void RunAllTests (void)
{
    RUN_TEST_GROUP(TDD);
    RUN_TEST_GROUP(STATE_MACHINE);
    RUN_TEST_GROUP(EP_BVA);
}

static void stubs_return(t_SWITCH name_of_switch, t_SWITCH_STATE state_of_switch, uint8_t sw_duration)
{
    #if STUBS_ENABLED
    SW_GetName_ExpectAndReturn(name_of_switch);
    SW_GetState_ExpectAndReturn(state_of_switch);
    SW_GetDuration_ExpectAndReturn(sw_duration);
    #endif
}

#endif