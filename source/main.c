#include "../test/unity/unity_fixture.h"
#define MAKE_UNITY_VERBOSE	argc = 2; argv[1] = "-v"

static void RunAllTests (void)
{
    RUN_TEST_GROUP(TDD);
    RUN_TEST_GROUP(STATE_MACHINE);
    RUN_TEST_GROUP(EP_BVA);
}

int main(int argc, char * argv[])
{
    MAKE_UNITY_VERBOSE;
    UnityMain(argc, argv, RunAllTests);

    return 0;
}
