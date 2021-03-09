#include "switch.h"

static t_SWITCH sw_name;
static t_SWITCH_STATE sw_state;
static uint8_t sw_duration;

t_SWITCH SW_GetName(void)
{
    return sw_name;
}

t_SWITCH_STATE SW_GetState(void)
{
    return sw_state;
}

uint8_t SW_GetDuration(void)
{
    return sw_duration;
}