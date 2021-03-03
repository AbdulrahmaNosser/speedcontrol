#include "fake_sw.h"
#include "../unity/unity_fixture.h"

TEST_GROUP(FakeSwitch);

TEST_SETUP(FakeSwitch)
{
    FAKE_SW_init();
}


TEST_TEAR_DOWN(FakeSwitch)
{
    FAKE_SW_destroy();
}

/*------------- Test Cases -------*/

/** Doxygen Test Case Description **/
TEST(FakeSwitch, switchesAreReleasedAfterInit)
{
    /*!
		  * @par Given : Switch State is unknown
		  * @par When  : Init is called
		  * @par Then  : Switch state is SW_RELEASED
	*/

    /* Note that init is called in TEST_SETUP() */
    LONGS_EQUAL(SW_RELEASED, FAKE_SW_getSwState());
}

/** Doxygen Test Case Description **/
TEST(FakeSwitch, setSwState)
{
    /*!
		  * @par Given : Switch State is Released
		  * @par When  : Switch State is set to SW_PREPRESSED
		  * @par Then  : Switch state is SW_PREPRESSED
	*/

    FAKE_SW_setSwState(SW_PREPRESSED);
    LONGS_EQUAL(SW_PREPRESSED, FAKE_SW_getSwState());
}



TEST_GROUP_RUNNER(FakeSwitch)
{
    RUN_TEST_CASE(FakeSwitch, switchesAreReleasedAfterInit);
    RUN_TEST_CASE(FakeSwitch, setSwState);
}

