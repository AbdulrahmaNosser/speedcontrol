/**
 * @file main.c
 * @brief The main function were the you can switch between testing with .txt files or testing with stubs
 * @note Please set the bulid target in CodeBlocks as **Release** to test with .txt files or as **Debug** to test with stubs
 * @attention Please set the **RELEASE** to true or false according to your bulid target
 */

#include <stdbool.h>

#include "../test/unity/unity_fixture.h"
#include "switch/switch.h"
#include "../test/speedcontrol_test/speedcontrol_test.h"

#define RELEASE true
#define DEBUG !RELEASE

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
        end_of_file = SW_GetFileEnd();
    }


    #endif
    return 0;
}
