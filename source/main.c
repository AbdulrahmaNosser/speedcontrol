/**
 * @file main.c
 * @brief This file has the entry program point main().
 * @details The main file were the you can switch between testing with .txt files or testing with stubs
 * @note Please set the build target in CodeBlocks as **Release** to test with .txt files or as **Debug** to test with stubs
 * @attention Please set the **RELEASE** to true or false according to your build target
 */
#include <stdbool.h>

#include "../test/unity/unity_fixture.h"
#include "switch/switch.h"
#include "../test/speedcontrol_test/speedcontrol_test.h"

/**
 * @brief Change to true or false to switch between testing with stubs and testing with .txt file.
 *
 */
#define RELEASE true

/**
 * @brief The inverse of the RELEASE macro to switch between testing with stubs and testing with .txt file.
 *
 */
#define DEBUG !RELEASE

/**
 * @brief Encapsulates all test group runner functions.
 * 
 */
#if DEBUG
static void RunAllTests (void)
{
    RUN_TEST_GROUP(TDD);
    RUN_TEST_GROUP(STATE_TRANSITION);
    RUN_TEST_GROUP(EP_BVA);
}
#endif

int main(int argc, char * argv[])
{
    int8_t end_of_file = NULL;

    #if DEBUG

    MAKE_UNITY_VERBOSE;
    UnityMain(argc, argv, RunAllTests);


    #elif RELEASE

    MotorInit ();
    while(end_of_file != EOF)
    {
        SW_Read();
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());
        end_of_file = SW_FileEnd();
    }


    #endif
    return 0;
}
