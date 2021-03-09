#include "../test/unity/unity_fixture.h"
#include "switch/switch.h"
#include "../test/speedcontrol_test/speedcontrol_test.h"


int main(int argc, char * argv[])
{
    // MAKE_UNITY_VERBOSE;
    // UnityMain(argc, argv, RunAllTests);
    SW_Read();
    return 0;
}
