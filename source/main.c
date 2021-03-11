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
        printf("%d %d %d\n", SW_GetName(), SW_GetState(), SW_GetDuration());
        MotorUpdate(SW_GetName(), SW_GetState(), SW_GetDuration());
        end_of_file = SW_GetFileEnd();
    }


    #endif
    return 0;
}
