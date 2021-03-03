/* Include Header File */
#include "fake_sw.h"

/* Switches States */
static SWITCH_STATE_t switchState;


void FAKE_SW_init(void)
{
    switchState = SW_RELEASED;
}

void FAKE_SW_destroy(void)
{
    /* Nothing to destroy, Just Initialize everything again */
    switchState = SW_RELEASED;
}

SWITCH_STATE_t FAKE_SW_getSwState(void)
{
    return switchState;
}

void FAKE_SW_setSwState(SWITCH_STATE_t state)
{
    switchState = state;
}

