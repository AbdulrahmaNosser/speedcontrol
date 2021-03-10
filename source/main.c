#include "../test/unity/unity_fixture.h"
#include "switch/switch.h"
#include "../test/speedcontrol_test/speedcontrol_test.h"


int main(int argc, char * argv[])
{

    #if DEBUG

    MAKE_UNITY_VERBOSE;
    UnityMain(argc, argv, RunAllTests);


    #elif RELEASE

    for (size_t i = 0; i < 4; i++)
    {
        SW_Read();
    }


    #endif
    return 0;
}
