#include "switch.h"

static t_SWITCH sw_name;
static t_SWITCH_STATE sw_state;
static uint8_t sw_duration;

t_SWITCH sw_get_name(void)
{
    return sw_name;
}

t_SWITCH_STATE sw_get_state(void)
{
    return sw_state;
}