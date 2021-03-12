/**
 * @file speedcontrol_test.h
 * @brief Encapsulates includes required for testing and some testing configurations.
 */

#ifndef SPEEDCONTROL_TEST_H
#define SPEEDCONTROL_TEST_H

#include <stdbool.h>

#include "../../source/speedcontrol/speedcontrol.h"
#include "../../source/switch/switch.h"

#include "../unity/unity_fixture.h"
#include "../mocks/Mockswitch.h"

/**
 * @brief change the value of STUBS_ENABLED to false to turn off stubs and to use real functions
 *@warning In order to use Unity with the real functions you must disable the mocks by removing it mocks files from the build. Not doing so will result in a compilation error as the auto generated mocks file contains functions with the same name as the real functions.
 */
#define STUBS_ENABLED true

#define MAKE_UNITY_VERBOSE	argc = 2; argv[1] = "-v"

#endif